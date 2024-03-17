#include<iostream>
#include<stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(nullptr);

	int n, ans = 0; cin >> n;
	string AB;
	while (n--) {
		stack<char>s;
		cin >> AB;
		for (auto& x : AB) {
			if (s.empty()) s.push(x);
			else if (x == 'A') {
				if (s.top() != 'A') s.push(x);
				else s.pop();
			}
			else {
				if (s.top() != 'B') s.push(x);
				else s.pop();
			}
		}
		if (s.empty()) ans++;
	}
	cout << ans;

	return 0;
}