

#include <iostream>
using namespace std;


#include "expression.h"
#include "subexpression.h"
#include "operand.h"

#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "greaterthan.h"
#include "lessthan.h"
#include "and.h"
#include "or.h"
#include "literal.h"
#include "equals.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
	this->left = left;
	this->right = right;
}

Expression* SubExpression::parse()
{
	Expression* left;
	Expression* right;
	char operation, paren;

	left = Operand::parse();
	cin >> operation;
	cout << operation;

	if (operation == '!') {    // negate
		left->negated = true;
		cin >> operation;
		cout << operation;
	}

	if (operation == ')') {  //  unary expression, end
		return left;


	} else {
		right = Operand::parse();
		cin >> paren;
		cout << paren;

		if (paren == '!') {
			right->negated = true;
			cin >> paren;
			cout << paren;
		}

	}

	switch (operation)
	{
	case '+':
		return new Plus(left, right);
	case '-':
		return new Minus(left, right);
	case '*':
		return new Times(left, right);
	case '/':
		return new Divide(left, right);
	case '>':
		return new GreaterThan(left, right);
	case '<':
		return new LessThan(left, right);
	case '&':
		return new And(left, right);
	case '|':
		return new Or(left, right);
	case '=':
		return new Equals(left, right);
	}
	return 0;
}
