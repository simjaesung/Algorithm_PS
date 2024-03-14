#include<iostream>
#include<string>
#include<stack>

using namespace std;

int isToken(const char token)
{
	char oper[4] = { '+','-','*','/' };
	for (auto x : oper) {
		if (token == x)	return 0;
	}
	return 1;
}

int main()
{
	double token[26] = { 0 };
	int n;
	double input, token1, token2, result;

	cin >> n;

	string postfix;
	cin >> postfix;

	for (int i = 0; i < n; i++) {
		cin >> input;
		token[i] = input;
	}

	stack<double>stack;

	for (auto x : postfix) {
		if (isToken(x))
			stack.push(token[int(x)-65]);
		else {
			token1 = stack.top();
			stack.pop();
			token2 = stack.top();
			stack.pop();

			switch (x)
			{
			case '+':
				result = token2 + token1;
				break;
			case '-':
				result = token2 - token1;
				break;
			case '*':
				result = token2 * token1;
				break;
			case '/':
				result = token2 / token1;
				break;
			}

			stack.push(result);
		}
	}
	printf("%.2f", result);
	return 0;
}