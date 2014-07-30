/*
 * Expression.cpp
 *
 *  Created on: 29/07/2014
 *      Author: vitor
 */

#include "Expression.h"

Expression::Expression(std::string expression) {
	auto infix_token_list = parse(expression);
	convert_to_postfix(infix_token_list);
}

std::vector<TokenPtr> Expression::parse(const std::string& expression) {
	std::vector<TokenPtr> infix_token_list;
	Tokenizer tokenizer(expression);
	auto current_token = tokenizer.get_token(repeat);
	int current_state = 1;

	while (current_token->type != Token::END) {
		switch (current_state) {
		case 0: // Operand state
			if (current_token->type == Token::OPERAND) {
				fprintf(stderr, "Malformed expression %s\n",
						expression.c_str());
				exit(1);
			} else if (current_token->type == Token::OPERATOR) {
				current_state = 1;
			}
			break;
		case 1: // Operator state
			if (current_token->type == Token::OPERAND) {
				current_state = 0;
			} else if (current_token->type == Token::OPERATOR) {
				fprintf(stderr, "Malformed expression %s\n",
						expression.c_str());
				exit(1);
			}
			break;
		}
		infix_token_list.push_back(std::move(current_token));
		current_token = tokenizer.get_token(repeat);
	}
	return infix_token_list;
}

void Expression::convert_to_postfix(std::vector<TokenPtr>& infix_token_list) {
	std::stack<TokenPtr> operator_stack;

	for (auto& token : infix_token_list) {
		if (token->type == Token::OPAREN) {
			operator_stack.push(std::move(token));
		} else if (token->type == Token::OPERAND) {
			postfix_token_list.push_back(std::move(token));
		} else if (token->type == Token::OPERATOR) {
			auto current_token_operator = static_cast<Operator*>(token.get());

			while (!operator_stack.empty()
					&& operator_stack.top()->type != Token::OPAREN) {
				auto stack_top_operator =
						static_cast<Operator*>(operator_stack.top().get());

				if (stack_top_operator->get_precedence()
						>= current_token_operator->get_precedence()) {
					postfix_token_list.push_back(
							std::move(operator_stack.top()));
					operator_stack.pop();
				} else {
					break;
				}
			}
			operator_stack.push(std::move(token));
		} else if (token->type == Token::CPAREN) {
			while (!operator_stack.empty()
					&& operator_stack.top()->type != Token::OPAREN) {
				postfix_token_list.push_back(std::move(operator_stack.top()));
				operator_stack.pop();
			}
			operator_stack.pop();
		} else {
			fprintf(stderr, "Could not identify token with type %d\n",
					token->type);
			exit(1);
		}
	}

	while (!operator_stack.empty()) {
		postfix_token_list.push_back(std::move(operator_stack.top()));
		operator_stack.pop();
	}
}

std::unique_ptr<Operand> Expression::allocate_correct_operand(
		Operand* operand) {
	switch (operand->operand_type) {
	case Operand::NUMBER:
		return std::unique_ptr<Operand>(
				new Number(*(static_cast<Number*>(operand))));
		break;
	case Operand::RAND:
		return std::unique_ptr<Operand>(
				new Rand(*(static_cast<Rand*>(operand))));
		break;
	case Operand::SIN:
		return std::unique_ptr<Operand>(new Sin(*(static_cast<Sin*>(operand))));
		break;
	case Operand::COS:
		return std::unique_ptr<Operand>(new Cos(*(static_cast<Cos*>(operand))));
		break;
	case Operand::REPEAT:
		return std::unique_ptr<Operand>(
				new Repeat(*(static_cast<Repeat*>(operand))));
		break;
	default:
		fprintf(stderr, "Unrecognized operand while allocating: %d\n",
				operand->operand_type);
		exit(1);
	}
}

float Expression::eval() {
	std::stack<std::unique_ptr<Operand>> operand_stack;

	for (auto& token : postfix_token_list) {
		if (token->type == Token::OPERAND) {
			operand_stack.push(
					allocate_correct_operand(
							static_cast<Operand*>(token.get())));
		} else if (token->type == Token::OPERATOR) {
			auto operator_el = static_cast<Operator*>(token.get());

			auto operand2 = std::move(operand_stack.top());
			operand_stack.pop();
			auto operand1 = std::move(operand_stack.top());
			operand_stack.pop();

			operand_stack.push(
					std::unique_ptr<Operand>(
							new Number(
									operator_el->operate(operand1->eval(),
											operand2->eval()))));
		} else {
			fprintf(stderr, "Unrecognized token found while eval'ing: %d\n",
					token->type);
			exit(1);
		}
	}
	return operand_stack.top()->eval();
}
