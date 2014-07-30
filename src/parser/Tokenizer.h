/*
 * Tokenizer.h
 *
 *  Created on: 29/07/2014
 *      Author: vitor
 */

#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "Token.h"
#include "Operator.h"
#include "Operand.h"

class Tokenizer {
private:
	std::string expression;
	int current = 0;

	void eat_whitespaces();
	bool is_whitespace();
	int find_matching_parenthesis_pos();

public:
	Tokenizer(std::string expression) :
			expression(expression) {
	}

	TokenPtr get_token(int& repeat_reference);
};

#endif /* TOKENIZER_H_ */
