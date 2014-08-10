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
#include "Parenthesis.h"
#include "End.h"

class Tokenizer {
private:
	std::string expression;
	int current;

	void eat_whitespaces();
	bool is_whitespace();
	int find_matching_parenthesis_pos();
	bool end_of_string();
	std::string get_number();

public:
	Tokenizer(std::string expression) :
			expression(expression), current(0) {
	}

	TokenPtr get_token(int* repeat_reference);
};

#endif /* TOKENIZER_H_ */
