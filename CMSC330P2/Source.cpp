#include <iostream>
#include <string>
#include <vector>
using namespace std;


#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

#include <iomanip>
#include <fstream>


SymbolTable symbolTable;

//void parseAssignments();


void parseAssignments()
{
	char assignop, delimiter;
	string variable;
	int value;
	do
	{
		variable = parseName();
		cin >> ws >> assignop >> value;
		cout << assignop << value;
		delimiter = cin.peek();

		if (delimiter == ',') {
			cin >> delimiter;
			cout << delimiter;
		}

		symbolTable.insert(variable, value);
	} while (delimiter == ',');


}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//ifstream inFile;
	//inFile.open("input.txt");


	while (!cin.eof()) {

		Expression* expression;
		char paren, comma;

		cout << "Expression: ";
		cin >> paren;
		cout << paren;
		expression = SubExpression::parse();
		if (cin.peek() == ',') {
			cin >> comma;
			cout << comma;
			parseAssignments();
		}

		if (cin.peek() != ';') {
			cout << "\nNo terminal ';' found!\n";
			return 1;
		} else cin >> comma;

		cout << "\nValue = " << expression->evaluate() << "\n\n";

		if (cin.peek() == EOF) {
			cout << "\n End of file.";
			return 0;
		}
	
	}  //  while

	system("pause");
	
	return 0;
}
