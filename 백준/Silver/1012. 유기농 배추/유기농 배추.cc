#include<iostream>
#include<algorithm>

using namespace std;
int arr[51][51], c[51][51];
int m, n, k;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int inrange(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	return 0;
}

void dfs(int x, int y)
{
	c[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (inrange(nx, ny)) {
			if(arr[nx][ny] == 1 && c[nx][ny] == 0)
				dfs(nx, ny);
		}
	}

}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < 51; i++) {
			fill(c[i], c[i] + 51, 0);
			fill(arr[i], arr[i] + 51, 0);
		}
	
		cin >> m >> n >> k;
		while (k--) {
			//x가로 y세로
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1 && c[i][j] == 0) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}
	
	
	return 0;
}
