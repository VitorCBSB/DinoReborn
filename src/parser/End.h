/*
 * End.h
 *
 *  Created on: 31/07/2014
 *      Author: vitor
 */

#ifndef END_H_
#define END_H_

#include "Token.h"

class End: public Token {
public:
	End() :
			Token(Token::END) {
	}
	TokenPtr clone() {
		return TokenPtr(new End(*this));
	}
};

#endif /* END_H_ */
