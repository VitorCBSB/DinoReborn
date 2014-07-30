/*
 * Tokenizer.cpp
 *
 *  Created on: 29/07/2014
 *      Author: vitor
 */

#include "Tokenizer.h"
#include "Expression.h" // To avoid cyclic includes

TokenPtr Tokenizer::get_token(int& repeat_reference) {
	eat_whitespaces();

	std::string special_name;
	int begin_expr_pos;

	switch (expression[current]) {
	case '+':
		current++;
		return TokenPtr(new Add());
	case '-':
		current++;
		return TokenPtr(new Sub());
	case '*':
		current++;
		return TokenPtr(new Mult());
	case '/':
		current++;
		return TokenPtr(new Div());
	case '(':
		current++;
		return TokenPtr(new Token(Token::OPAREN));
	case ')':
		current++;
		return TokenPtr(new Token(Token::CPAREN));
	case '$': // Special variables
		current++;
		while (!is_whitespace() && !end_of_string()
				&& expression[current] != '(') {
			special_name.push_back(expression[current]);
			current++;
		}

		if (special_name == "rand") {
			return TokenPtr(new Rand());
		} else if (special_name == "sin") {
			current++; // Skip parenthesis
			begin_expr_pos = current;
			current = find_matching_parenthesis_pos();
			current++; // Skip close parenthesis
			return TokenPtr(
					new Sin(
							new Expression(
									expression.substr(begin_expr_pos,
											(current - 1) - begin_expr_pos))));
		} else if (special_name == "cos") {
			current++; // Skip parenthesis
			begin_expr_pos = current;
			current = find_matching_parenthesis_pos();
			current++; // Skip close parenthesis
			return TokenPtr(
					new Cos(
							new Expression(
									expression.substr(begin_expr_pos,
											(current - 1) - begin_expr_pos))));
		} else if (special_name == "repeat") {
			return TokenPtr(new Repeat(repeat_reference));
		} else {
			fprintf(stderr, "Could not identify special name %s\n",
					special_name.c_str());
			exit(1);
		}
	case '\0':
		return TokenPtr(new Token(Token::END));
	default: // Number
		begin_expr_pos = current;
		current = expression.find_first_not_of("0123456789.", begin_expr_pos);
		return TokenPtr(
				new Number(
						std::stod(
								expression.substr(begin_expr_pos,
										current - begin_expr_pos))));
	}
}

int Tokenizer::find_matching_parenthesis_pos() {
	int position = current;
	// Dummy stack, only thing that matters
	// is knowing if it's empty or not.
	std::stack<int> parens_stack;
	parens_stack.push(0);

	while (!parens_stack.empty()) {
		position++;
		if (expression[position] == '(') {
			parens_stack.push(0);
		}
		if (expression[position] == ')') {
			parens_stack.pop();
		}
	}
	return position;
}

bool Tokenizer::end_of_string() {
	return expression[current] == '\0';
}

void Tokenizer::eat_whitespaces() {
	while (is_whitespace()) {
		current++;
	}
}

bool Tokenizer::is_whitespace() {
	return expression[current] == ' ' || expression[current] == '\t'
			|| expression[current] == '\n' || expression[current] == '\r';
}
