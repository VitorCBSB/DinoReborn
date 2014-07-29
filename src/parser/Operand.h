/*
 * Operand.h
 *
 *  Created on: 29/07/2014
 *      Author: vitor
 */

#ifndef OPERAND_H_
#define OPERAND_H_

#include "Token.h"
#include <stdlib.h>
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
};

class Number: public Operand {
private:
	float number;

public:
	Number(float number) :
			Operand(OperandType::NUMBER), number(number) {
	}
};

class Rand: public Operand {
public:
	Rand() :
			Operand(OperandType::RAND) {
	}
};

class Sin: public Operand {
private:
	std::unique_ptr<Expression> expression;

public:
	Sin(Expression* expression) :
			Operand(OperandType::SIN), expression(
					std::unique_ptr<Expression>(expression)) {
	}
};

class Cos: public Operand {
private:
	std::unique_ptr<Expression> expression;

public:
	Cos(Expression* expression) :
			Operand(OperandType::COS), expression(
					std::unique_ptr<Expression>(expression)) {
	}
};

class Repeat: public Operand {
public:
	Repeat() :
			Operand(OperandType::REPEAT) {
	}
};

#endif /* OPERAND_H_ */
