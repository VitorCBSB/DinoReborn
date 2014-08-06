/*
 * Token.h
 *
 *  Created on: 29/07/2014
 *      Author: vitor
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include <memory>

class Token {
public:
	enum Type {
		OPERAND, OPERATOR, PARENTHESIS, END
	} type;

	Token(Type type) :
			type(type) {
	}

	virtual ~Token() {
	}

	virtual std::unique_ptr<Token> clone(int* repeat_reference = 0) = 0;
};

typedef std::unique_ptr<Token> TokenPtr;

#endif /* TOKEN_H_ */
