#include<string>
#include "tstack.h"

using namespace std;

int priority(char op)
{
	if (op == '*' || op == '/')
		return 3;
	else if (op == '+' || op == '-')
		return 2;
	else if (op == ')')
		return 1;
	else if (op == '(')
		return 0;	
	else
		throw "is not op";
}

char* toPostfix(char* oldString)
{
	TStack<char> operators;
	char* postfixString = new char[strlen(oldString)]; //podtfixstring is an array of 1 elem
	int g = 0;
	for (int i = 0; i < strlen(oldString); i++)//i < strlen(oldString) is false
	{
		if (isdigit(oldString[i]))
		{
			postfixString[g] = oldString[i];
			g++;
		}
		else if (oldString[i] == '(')
			operators.push('(');
		else if (oldString[i] == ')')
		{
			char stackTop = operators.pull();
			while (stackTop != '(')
			{
				postfixString[g] = stackTop;
				g++;
				stackTop = operators.pull();
			}
		}
		//else if (oldString[i] == '=')
		//	break;
		else //если оператор
		{
			if (operators.isEmpty())
				operators.push(oldString[i]);
			else
			{
				int curPrior = priority(oldString[i]);
				char stackTop = operators.pull();
				int stackPrior = priority(stackTop);
				if (stackPrior < curPrior)
				{
					operators.push(stackTop);
					operators.push(oldString[i]);
				}
				else
				{
					while ((stackPrior >= curPrior) && (!(operators.isEmpty())))
					{
						postfixString[g] = stackTop;
						stackTop = operators.pull();
						stackPrior = priority(stackTop);
						g++;
					}
					operators.push(stackTop);
					operators.push(oldString[i]);
				}
			}
		}
	}
	while (!(operators.isEmpty())) //????
	{
		postfixString[g] = operators.pull(); //!!!
		g++;//??????
	}
	postfixString[g] = 0;
	return postfixString;
}

double postfixCalc(char* postfixString)
{
	TStack<double> numbers;
	TStack<char> operators;
	for (int i = 0; i < strlen(postfixString); i++)
	{
		char cur = postfixString[i];
		if (isdigit(cur))//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			numbers.push(cur - '0');
		else if (cur == '+' || cur == '-' || cur == '*' || cur == '/')
			operators.push(cur);
		else if (cur == '=')
		{
			while (!(operators.isEmpty()))
			{
				char op = operators.top();
				operators.pull();
				double num2 = numbers.top();
				numbers.pull();
				double num1 = numbers.top();
				numbers.pull();

				if (op == '+')
					numbers.push(num1 + num2);
				else if (op == '-')
					numbers.push(num1 - num2);
				else if (op == '*')
					numbers.push(num1 * num2);
				else if (op == '/')
					numbers.push(num1 / num2);
			}
		}
	}
	return numbers.top();
}
