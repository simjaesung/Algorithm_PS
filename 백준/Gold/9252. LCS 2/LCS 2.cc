#include<iostream>
using namespace std;
int d[1005][1005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
			else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}

	int x = s1.length(); int y = s2.length();
	string ans;
	while (x > 0 && y > 0) {
		if (d[x][y] == d[x - 1][y]) x--;
		else if (d[x][y] == d[x][y - 1]) y--;
		else {
			ans += s1[x-1];
			x--; y--;
		}
	}
	cout << d[s1.length()][s2.length()] << '\n';
	for (int i = ans.length() - 1; i >= 0; i--) cout << ans[i];

	return 0;
}