#include<iostream>
#include<algorithm>
using namespace std;

int n, min_number = 100, max_number = 0;
int arr[105][105];
int high[105][105];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int inrange(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < n)return 1;
	return 0;
}

void dfs(int x, int y, int water)
{
	high[x][y] = 1;
	for (int i = 0; i < n; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (inrange(nx, ny)) {
			if (arr[nx][ny] > water && high[nx][ny] == 0)
				dfs(nx, ny, water);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			//min_number = min(min_number, arr[i][j]);
			max_number = max(max_number, arr[i][j]);
		}
	}

	int ans = 0;

	for (int water = 0; water <= max_number; water++) {
		for (int i = 0; i < n; i++)
			fill(high[i], high[i] + n, 0);

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > water && high[i][j] == 0) {
					dfs(i, j, water);
					cnt++;
				}	
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans;
	return 0;
}