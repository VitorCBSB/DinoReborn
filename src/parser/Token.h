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
		OPERAND, OPERATOR, OPAREN, CPAREN, END
	} type;

	Token(Type type) :
			type(type) {
	}

	virtual ~Token() {
	}
};

typedef std::unique_ptr<Token> TokenPtr;

#endif /* TOKEN_H_ */
