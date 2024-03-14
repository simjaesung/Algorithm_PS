#include <iostream>
#include<string>
#include <stack>

using namespace std;

int isToken(const char token)
{
	char oper[6] = { '+','-','*','/','(',')' };
	for (auto x : oper) {
		if (token == x)	return 0;
	}

	return 1;
}

int getpriority(const char token)
{
	switch (token)
	{
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '(':
		return 0;
	default:
		break;
	}
}


int main()
{
	string infix, postfix;
	cin >> infix;

	stack<char>stack;

	for (auto x : infix) {
		if (isToken(x))
			postfix += x;
		else {
			if (x == ')') {
				while (stack.top() != '(') {
					postfix += stack.top();
					stack.pop();
				}
				stack.pop();
			}			
			else if (x == '(' || stack.empty() || 
				getpriority(stack.top()) < getpriority(x)) {
				stack.push(x);
			}
			else {
				while (!stack.empty() && getpriority(stack.top()) >= getpriority(x)){
					postfix += stack.top();
					stack.pop();
				}
				stack.push(x);
			}
		}
	}

	while (!stack.empty()) {
		postfix += stack.top();
		stack.pop();
	}

	cout << postfix;
	return 0;
}