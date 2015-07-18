#ifndef _NODES_H
#define _NODES_H

#include <memory>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

class Expr {
public:
	virtual double eval() const = 0;
	virtual void set_repeat_to(int new_value) = 0;
	virtual std::unique_ptr<Expr> clone() = 0;
	virtual ~Expr() {
	}
};

class NodeOper : public Expr {
protected:
	std::unique_ptr<Expr> op1, op2;
public:
	NodeOper(Expr* op1, Expr* op2)
		: op1(std::unique_ptr<Expr>(op1)), op2(std::unique_ptr<Expr>(op2)) {
	}
	virtual ~NodeOper() {
	}
	void set_repeat_to(int new_value) {
		op1->set_repeat_to(new_value);
		op2->set_repeat_to(new_value);
	}
};

class Add : public NodeOper {
public:
	Add(Expr* op1, Expr* op2) : NodeOper(op1, op2) {
	}
	double eval() const {
		return op1->eval() + op2->eval();
	}
	virtual std::unique_ptr<Expr> clone() {
		return std::unique_ptr<Expr>(
				new Add(op1->clone().release(), op2->clone().release()));
	}
};

class Sub : public NodeOper {
public:
	Sub(Expr* op1, Expr* op2) : NodeOper(op1, op2) {
	}
	double eval() const {
		return op1->eval() - op2->eval();
	}
	virtual std::unique_ptr<Expr> clone() {
		return std::unique_ptr<Expr>(
				new Sub(op1->clone().release(), op2->clone().release()));
	}
};

class Mult : public NodeOper {
public:
	Mult(Expr* op1, Expr* op2) : NodeOper(op1, op2) {
	}
	double eval() const {
		return op1->eval() * op2->eval();
	}
	virtual std::unique_ptr<Expr> clone() {
		return std::unique_ptr<Expr>(
				new Mult(op1->clone().release(), op2->clone().release()));
	}
};

class Div : public NodeOper {
public:
	Div(Expr* op1, Expr* op2) : NodeOper(op1, op2) {
	}
	double eval() const {
		return op1->eval() / op2->eval();
	}
	virtual std::unique_ptr<Expr> clone() {
		return std::unique_ptr<Expr>(
				new Div(op1->clone().release(), op2->clone().release()));
	}
};

class Rand : public Expr {
public:
	double eval() const {
		return (double) rand() / RAND_MAX;
	}
	void set_repeat_to(int new_value) {
	}
	virtual std::unique_ptr<Expr> clone() {
		return std::unique_ptr<Expr>(new Rand());
	}
};

class Repeat : public Expr {
private:
	int current_value = 0;
public:
	Repeat(int current_value = 0) : current_value(current_value) {
	}
	double eval() const {
		return current_value;
	}
	void set_repeat_to(int new_value) {
		current_value = new_value;
	}
	virtual std::unique_ptr<Expr> clone() {
		return std::unique_ptr<Expr>(new Repeat(current_value));
	}
};

class Sin : public Expr {
private:
	std::unique_ptr<Expr> expr;
public:
	Sin(Expr* expr) : expr(std::unique_ptr<Expr>(expr)) {
	}
	double eval() const {
		return sin(expr->eval());
	}
	void set_repeat_to(int new_value) {
	}
	virtual std::unique_ptr<Expr> clone() {
		return std::unique_ptr<Expr>(new Sin(expr->clone().release()));
	}
};

class Cos : public Expr {
private:
	std::unique_ptr<Expr> expr;
public:
	Cos(Expr* expr) : expr(std::unique_ptr<Expr>(expr)) {
	}
	double eval() const {
		return cos(expr->eval());
	}
	void set_repeat_to(int new_value) {
	}
	virtual std::unique_ptr<Expr> clone() {
		return std::unique_ptr<Expr>(new Cos(expr->clone().release()));
	}
};

class Neg : public Expr {
private:
	std::unique_ptr<Expr> expr;
public:
	Neg(Expr* expr) : expr(std::unique_ptr<Expr>(expr)) {
	}
	double eval() const {
		return -expr->eval();
	}
	void set_repeat_to(int new_value) {
	}
	virtual std::unique_ptr<Expr> clone() {
		return std::unique_ptr<Expr>(new Neg(expr->clone().release()));
	}
};

class Num : public Expr {
private:
	double val;
public:
	Num(double val) : val(val) {
	}
	double eval() const {
		return val;
	}
	void set_repeat_to(int new_value) {
	}
	virtual std::unique_ptr<Expr> clone() {
		return std::unique_ptr<Expr>(new Num(val));
	}
};

#endif

