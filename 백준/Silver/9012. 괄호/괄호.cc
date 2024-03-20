#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n; cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int ans = 0;
		for (auto& x : s) {
			if (x == '(') ans++;
			else ans--;

			if (ans < 0) break;
		}

		if (ans != 0) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}