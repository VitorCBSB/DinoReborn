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

class Expression {
private:
	// List of tokens in postfix format
	// That is: a b `f` c `g`
	std::vector<TokenPtr> postfix_token_list;
	int repeat = 0;

	std::vector<TokenPtr> parse(const std::string& expression);
	void convert_to_postfix(std::vector<TokenPtr>& infix_token_list);
	std::unique_ptr<Operand> allocate_correct_operand(Operand* operand);
	float evaluate_postfix();

	float eval_operand(const Operand& operand);

public:
	Expression(std::string expression);

	float eval();
	void increment_repeat() {
		repeat++;
	}
};

#endif /* EXPRESSION_H_ */
