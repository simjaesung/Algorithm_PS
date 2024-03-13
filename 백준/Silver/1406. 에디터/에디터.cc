#include<iostream>
#include<stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	string s;
	int n;
	cin >> s >> n;

	stack<char>left;
	stack<char>right;

	for (auto& x : s) left.push(x);

	while (n--) {
		char cmd;
		cin >> cmd;

		if (cmd == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (cmd == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (cmd == 'B') {
			if (!left.empty()) left.pop();
		}
		else if (cmd == 'P') {
			char c; cin >> c;
			left.push(c);
		}
	}
	s = "";
	while (!(left.empty())) {
		s += left.top();
		left.pop();
	}

	for (int i = 0; i < s.length() / 2; i++) {
		char tmp = s[i];
		s[i] = s[s.length() - 1 - i];
		s[s.length() - i - 1] = tmp;
	}

	while (!(right.empty())) {
		s += right.top();
		right.pop();
	}

	cout << s;
	return 0;
}