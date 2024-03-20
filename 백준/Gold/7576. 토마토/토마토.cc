#include<iostream>
#include<queue>
using namespace std;

int box[1005][1005], c[1005][1005] = { 0 };
int m, n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int inrange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	return 0;
}

queue<pair<int, int>>q;

void bfs()
{
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (inrange(nx, ny)) {
				if (box[nx][ny] == 0) {
					box[nx][ny] = box[cx][cy] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;

	int check = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) q.push(make_pair(i, j));
		}
	}

	bfs();

	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0;
			}
			ans = max(ans, box[i][j]);
		}
	}
	cout << ans - 1;

	return 0;
}