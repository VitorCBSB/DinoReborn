/*
 * Parenthesis.h
 *
 *  Created on: 31/07/2014
 *      Author: vitor
 */

#ifndef PARENTHESIS_H_
#define PARENTHESIS_H_

#include "Token.h"

class Parenthesis: public Token {
public:
	enum ParenthesisType {
		OPAREN, CPAREN
	} parenthesis_type;

	Parenthesis(ParenthesisType type) :
			Token(Token::PARENTHESIS), parenthesis_type(type) {
	}
	virtual ~Parenthesis() {
	}

	TokenPtr clone(int* repeat_reference) {
		return TokenPtr(new Parenthesis(*this));
	}
};

#endif /* PARENTHESIS_H_ */
