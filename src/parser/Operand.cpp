/*
 * Operand.cpp
 *
 *  Created on: 30/07/2014
 *      Author: vitor
 */

#include "Operand.h"
#include "Expression.h"

float Number::eval() const {
	return number;
}

float Rand::eval() const {
	std::random_device rd;
	return (float) rd() / (float) rd.max();
}

float Sin::eval() const {
	return sin((M_PI / 180.0) * expression->eval());
}

float Cos::eval() const {
	return cos((M_PI / 180.0) * expression->eval());
}

float Repeat::eval() const {
	return repeat_reference;
}
