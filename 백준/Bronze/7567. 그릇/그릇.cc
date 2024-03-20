#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	char tmp = s[0];
	int ans = 10;
	for (int i = 1; i < s.length(); i++) {
		if (tmp == s[i]) ans += 5;
		else {
			ans += 10;
			tmp = s[i];
		}
	}
	cout << ans;

	return 0;
}