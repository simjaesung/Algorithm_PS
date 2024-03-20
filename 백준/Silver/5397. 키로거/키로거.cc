#include<iostream>
#include<stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(nullptr);
	int n; cin >> n;

	stack<char>left;
	stack<char>right;
	
	while (n--) {
		string s; cin >> s;

		for (auto& x : s) {
			if (x == '<') {
				if (!left.empty()) {
					right.push(left.top());
					left.pop();
				}
			}
			else if (x == '>') {
				if (!right.empty()) {
					left.push(right.top());
					right.pop();
				}
			}
			else if (x == '-') {
				if (!left.empty()) left.pop();
			}
			else left.push(x);
		}

		s = "";

		while (!left.empty()) {
			s += left.top();
			left.pop();
		}

		for (int i = 0; i < s.length() / 2; i++) {
			char tmp = s[i];
			s[i] = s[s.length() - 1 - i];
			s[s.length() - 1 - i] = tmp;
		}

		while (!right.empty()) {
			s += right.top();
			right.pop();
		}

		cout << s << '\n';
	}
	
	return 0;
}