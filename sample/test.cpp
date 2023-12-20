#include <iostream>
#include "tpostfix.h"

int main()
{
	char *s = new char [255];
	std::cin >> s;
	char* pString = toPostfix(s);
	double res = postfixCalc(pString);
	std::cout << res << std::endl;
}