#include<iostream>
#include<vector>
using namespace std;

bool check[20001];
int mark[20001];
vector<int> c[20001];

void dfs(int x,int marking)
{
	check[x] = true;
	if(mark[x] == 0) mark[x] = marking;

	for (int i = 0; i < c[x].size(); i++) {
		int y = c[x][i];
		if (!check[y]) {
			if (marking == 1) dfs(y, 2);
			else dfs(y, 1);
		}
	}
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int k; cin >> k;

	while (k--)
	{
		fill(check, check + 20001, false);
		fill(mark, mark + 20001, 0);
		for (int i = 0; i < 20001; i++)	c[i].clear();
		
		int v, e;
		cin >> v >> e;
		while (e--) {
			int a, b;
			cin >> a >> b;
			c[a].push_back(b);
			c[b].push_back(a);
		}
		for(int i = 1; i<=v; i++) dfs(i, 1);

		int anscheck = 1;

		for (int i = 1; i <= v; i++) {
			for (int j = 0; j < c[i].size(); j++) {
				if (mark[i] == mark[c[i][j]]) anscheck = 0;
			}
		} 

		if (anscheck || v == 1) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}