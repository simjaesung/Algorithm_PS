#include<iostream>
#include<vector>
using namespace std;
vector<int>g[100005];
int parent[100005];

void dfs(int x)
{
	for (int i = 0; i < g[x].size(); i++) {
		if (parent[g[x][i]] == 0) {
			parent[g[x][i]] = x;
			dfs(g[x][i]);
		}
	}
}


int main()
{
	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b); g[b].push_back(a);
	}

	dfs(1);
	for (int i = 2; i <= n; i++) cout << parent[i] << '\n';

	return 0;
}