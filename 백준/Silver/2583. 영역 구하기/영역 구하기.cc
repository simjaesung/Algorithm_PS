#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[105][105], v[105][105];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int m, n, k;

void dfs(int x, int y,int cnt)
{
	v[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

		if (arr[nx][ny] == 0 && v[nx][ny] == 0) dfs(nx, ny, cnt);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n >> k;

	while (k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = m - y2; i < m - y1; i++) {
			for (int j = x1; j < x2; j++) arr[i][j] = 1;
		}
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0 && v[i][j] == 0)
				dfs(i, j, ++cnt);
		}
	}

	cout << cnt << '\n';

	vector<int>ans(cnt);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] != 0) ans[v[i][j] - 1]++;
		}
	}

	sort(ans.begin(), ans.end());
	for (auto x : ans) cout << x << ' ';
	return 0;
}