#include<iostream>
#include<vector>
using namespace std;

int arr[505][505], c[505][505] = { 0 };
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int inrange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	return 0;
}

void dfs(int x, int y, int cnt)
{
	c[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (inrange(nx, ny)) {
			if (arr[nx][ny] == 1 && c[nx][ny] == 0)
				dfs(nx, ny, cnt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && c[i][j] == 0)
				dfs(i, j, ++cnt);
		}
	}
	cout << cnt << '\n';

	if (cnt == 0) {
		cout << 0;
		return 0;
	}
	
	vector<int>v(cnt);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] != 0) v[c[i][j] - 1]++;
		}	
	}

	int ans = 0;
	for (int i = 0; i < cnt; i++) ans = max(v[i], ans);

	cout << ans;

	return 0;
}