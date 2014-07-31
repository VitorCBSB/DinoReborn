/*
 * Operand.h
 *
 *  Created on: 29/07/2014
 *      Author: vitor
 */

#ifndef OPERAND_H_
#define OPERAND_H_

#include "Token.h"
#include <math.h>
#include <random>

class Expression;

class Operand: public Token {
public:
	enum OperandType {
		NUMBER, RAND, SIN, COS, REPEAT
	} operand_type;

	Operand(OperandType type) :
			Token(Token::OPERAND), operand_type(type) {
	}
	virtual ~Operand() {
	}

	virtual float eval() const = 0;
};

class Number: public Operand {
private:
	float number;

public:
	Number(float number) :
			Operand(OperandType::NUMBER), number(number) {
	}

	float eval() const;
	TokenPtr clone() {
		return TokenPtr(new Number(*this));
	}
};

class Rand: public Operand {
public:
	Rand() :
			Operand(OperandType::RAND) {
	}

	float eval() const;
	TokenPtr clone() {
		return TokenPtr(new Rand(*this));
	}
};

class Sin: public Operand {
private:
	std::shared_ptr<Expression> expression;

public:
	Sin(Expression* expression) :
			Operand(OperandType::SIN), expression(
					std::shared_ptr<Expression>(expression)) {
	}

	float eval() const;
	TokenPtr clone() {
		return TokenPtr(new Sin(*this));
	}
};

class Cos: public Operand {
private:
	std::shared_ptr<Expression> expression;

public:
	Cos(Expression* expression) :
			Operand(OperandType::COS), expression(
					std::shared_ptr<Expression>(expression)) {
	}

	float eval() const;
	TokenPtr clone() {
		return TokenPtr(new Cos(*this));
	}
};

class Repeat: public Operand {
private:
	int& repeat_reference;

public:
	Repeat(int& repeat_reference) :
			Operand(OperandType::REPEAT), repeat_reference(repeat_reference) {
	}

	float eval() const;
	TokenPtr clone() {
		return TokenPtr(new Repeat(*this));
	}
};

#endif /* OPERAND_H_ */
