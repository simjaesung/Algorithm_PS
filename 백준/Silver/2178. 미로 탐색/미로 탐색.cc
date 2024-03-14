#include<iostream>
#include<queue>
using namespace std;
int n, m;
int arr[105][105], c[105][105] = { 0 };
int ans = 10001;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int inrange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	return 0;
}

void bfs(int x, int y, int cnt)
{
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	c[x][y] = cnt;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (inrange(nx, ny)) {
				if (arr[nx][ny] == 1) {
					if (c[nx][ny] == 0) {
						c[nx][ny] = c[cx][cy] + 1;
						q.push(make_pair(nx, ny));
					}
					else c[nx][ny] = min(c[nx][ny], c[cx][cy] + 1);
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	bfs(0, 0, 1);
	cout << c[n-1][m-1];

	return 0;
}