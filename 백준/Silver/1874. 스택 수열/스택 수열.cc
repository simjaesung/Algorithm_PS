#include<iostream>
#include<stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(nullptr);
	int n; cin >> n;
	string ans;
	stack<int>s;

	int cnt = 0;
	while (n--) {
		int val; cin >> val;
		if (val > cnt) {
			int tmp = val - cnt;
			while (tmp--) {
				ans += '+';
				s.push(++cnt);
			}
		}
		else {
			while (!s.empty() && s.top() != val) {
				s.pop();
				ans += '-';
			}
			if (s.empty() || s.top() != val) {
				cout << "NO"; return 0;
			}
		}	

		s.pop();
		ans += '-';
	}
	for (auto& x : ans) cout << x << '\n';
	
	return 0;
}