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
	auto current_token = tokenizer.get_token();
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
		current_token = tokenizer.get_token();
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

	infix_token_list.clear();
}

float Expression::eval() {
	return 0.0;
}
