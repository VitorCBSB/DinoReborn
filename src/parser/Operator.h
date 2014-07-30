/*
 * Operator.h
 *
 *  Created on: 29/07/2014
 *      Author: vitor
 */

#ifndef OPERATOR_H_
#define OPERATOR_H_

#include "Token.h"

class Operator: public Token {
private:
	int precedence = 0;

public:
	enum OperatorType {
		ADD, SUB, MULT, DIV
	} operator_type;

	Operator(OperatorType type, int precedence) :
			Token(Token::OPERATOR), precedence(precedence), operator_type(type) {
	}
	virtual ~Operator() {
	}

	int get_precedence() {
		return precedence;
	}

	virtual float operate(float operand1, float operand2) = 0;
};

class Add: public Operator {
public:
	Add() :
			Operator(Operator::ADD, 1) {
	}

	float operate(float operand1, float operand2) {
		return operand1 + operand2;
	}
};

class Sub: public Operator {
public:
	Sub() :
			Operator(Operator::SUB, 1) {
	}

	float operate(float operand1, float operand2) {
		return operand1 - operand2;
	}
};

class Mult: public Operator {
public:
	Mult() :
			Operator(Operator::MULT, 2) {
	}

	float operate(float operand1, float operand2) {
		return operand1 * operand2;
	}
};

class Div: public Operator {
public:
	Div() :
			Operator(Operator::DIV, 2) {
	}

	float operate(float operand1, float operand2) {
		return operand1 / operand2;
	}
};

#endif /* OPERATOR_H_ */
