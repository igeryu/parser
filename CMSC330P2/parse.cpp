//  Ok:
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#include "parse.h"

string parseName()
{
	char alnum;
	string name = "";

	cin >> ws;
	while (isalnum(cin.peek()))
	{
		cin >> alnum;
		cout << alnum;
		name += alnum;
	}
	return name;
}

