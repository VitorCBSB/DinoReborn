/*
 * Expression.h
 *
 *  Created on: 18/07/2015
 *      Author: vitor
 */

#ifndef PARSER_EXPRESSION_H_
#define PARSER_EXPRESSION_H_

#include "ExprNodes.h"
#include "ExprParser.tab.h"
#include <memory>

class Expression {
private:
	std::unique_ptr<Expr> root;
public:
	Expression(const std::string& expression);
	Expression(const Expression& other) {
		root = other.root->clone();
	}
	Expression& operator=(const Expression& other) {
		root = other.root->clone();
		return *this;
	}
	double eval() const;
	void set_repeat_to(int new_value);
};

#endif /* PARSER_EXPRESSION_H_ */
