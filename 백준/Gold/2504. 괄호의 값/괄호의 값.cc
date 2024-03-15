#include<iostream>
#include<stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(nullptr);
	string s; cin >> s;
	stack<char>stack;
	//(([][]))
	int val = 1, ans = 0, result = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			val *= 2;
			stack.push(s[i]);
		}
		else if (s[i] == '[') {
			val *= 3;
			stack.push(s[i]);
		}
		else if (s[i] == ')') {
			if (stack.empty() || stack.top() != '(') {
				cout << 0;
				return 0;
			}
			stack.pop();
			if (i > 0 && s[i - 1] == '(') ans += val; 
			val /= 2;
			
		}
		else if (s[i] == ']') {
			if (stack.empty() || stack.top() != '[') {
				cout << 0;
				return 0;
			}
			stack.pop();

			if (i > 0 && s[i - 1] == '[') ans += val; 
			val /= 3;	
		}
	}

	if (stack.empty()) cout << ans;
	else cout << 0;
	
	return 0;
}