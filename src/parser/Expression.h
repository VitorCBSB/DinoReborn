/*
 * Expression.h
 *
 *  Created on: 29/07/2014
 *      Author: vitor
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <vector>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <functional>
#include "Token.h"
#include "Tokenizer.h"
#include "Operator.h"
#include "Operand.h"
#include "Parenthesis.h"

class Expression {
private:
	// List of tokens in postfix format
	std::vector<TokenPtr> postfix_token_list;
	int repeat = 0;

	std::vector<TokenPtr> parse(const std::string& expression);
	void convert_to_postfix(std::vector<TokenPtr>& infix_token_list);
	float evaluate_postfix();

	std::unique_ptr<Operand> cast_to_operand(TokenPtr& token);

public:
	Expression(std::string expression);
	Expression(const Expression& other) :
			repeat(other.repeat) {
		for (auto& token : other.postfix_token_list) {
			postfix_token_list.push_back(token->clone());
		}
	}

	float eval();
	void increment_repeat() {
		repeat++;
	}
};

#endif /* EXPRESSION_H_ */
