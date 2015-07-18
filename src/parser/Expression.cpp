/*
 * Expression.cpp
 *
 *  Created on: 18/07/2015
 *      Author: vitor
 */

#include "Expression.h"

Expression::Expression(const std::string& expression) {
	root = parse_and_get_ast(expression);
}

double Expression::eval() const {
	return root->eval();
}

void Expression::set_repeat_to(int new_value) {
	root->set_repeat_to(new_value);
}
