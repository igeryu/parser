
#include <strstream>
#include <vector>
using namespace std;

#include "expression.h"
#include "operand.h"
#include "variable.h"
#include "symboltable.h"


extern SymbolTable symbolTable;

Variable::Variable(string name)
{
	this->name = name;
}

int Variable::evaluate()
{

	int mod = negated ? 0 : 1;
	int value = symbolTable.lookUp(name);
	
	if (value != 0)
		return mod * value;

	return !mod;
}

