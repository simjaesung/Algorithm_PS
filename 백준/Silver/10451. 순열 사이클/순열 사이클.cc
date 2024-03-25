#include<iostream>
using namespace std;
int s[1005], c[1005];

void dfs(int x)
{
	c[x] = 1;
	if (!c[s[x]]) dfs(s[x]);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < 1005; i++) c[i] = 0;
		int ans = 0;
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> s[i];

		for (int i = 1; i <= n; i++) {
			if (!c[s[i]]) {
				dfs(s[i]); ans++;
			}
		}
		cout << ans <<'\n';
	}
	return 0;
}