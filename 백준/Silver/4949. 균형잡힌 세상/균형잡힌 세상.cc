#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	string s;
	
	while (getline(cin, s)) {
		if (s == ".") break;
		stack<char>stack;
		string ans = "yes";
		for (auto& x : s) {
			if (x == '[' || x == '(')
				stack.push(x);
			else if (x == ']' || x == ')') {
				if (x == ']') {
					if (stack.empty() || stack.top() != '[') {
						ans = "no";
						break;
					}
					else stack.pop();
				}
				if (x == ')') {
					if (stack.empty() || stack.top() != '(') {
						ans = "no";
						break;
					}
					else stack.pop();
				}
			}
			else continue;
		}

		if (!stack.empty()) ans = "no";
		cout << ans << '\n';

	}
	return 0;
}