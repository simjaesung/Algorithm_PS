#include<iostream>
#include<vector>
using namespace std;

vector<int> c[1001];
bool check[1001];

void dfs(int x)
{
	check[x] = true;
	for (int i = 0; i < c[x].size(); i++) {
		int y = c[x][i];
		if (!check[y]) dfs(y);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		c[a].push_back(b);
		c[b].push_back(a);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			dfs(i);
			ans++;
		}
	}

	cout << ans;
	return 0;
}