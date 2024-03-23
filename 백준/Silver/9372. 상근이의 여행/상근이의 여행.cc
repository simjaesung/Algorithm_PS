#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int c[10005], ans = 0;
vector<vector<int>>v(1005);
void dfs(int a)
{
	ans++; c[a] = 1;
	for (int i = 0; i < v[a].size(); i++) {
		int na = v[a][i];
		if (!c[na]) dfs(na);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while (n--) {
		ans = 0;
		fill(c, c + 10005, 0); //v.clear();
		for (int i = 0; i < 1005; i++) v[i].clear();
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		dfs(1);
		cout << ans - 1 << '\n';
	}
	return 0;
}