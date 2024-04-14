#include<iostream>
#include<tuple>
#include<queue>
#include<limits.h>
using namespace std;

int n, m, k;
int arr[1005][1005], c[1005][1005][15];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool inrange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main()
{
	
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int s = 0; s <= k; s++) {
				c[i][j][s] = -1;
			}
		}
	}

	queue<tuple<int, int, int>>q;
	q.push({ 0,0,0 }); c[0][0][0] = 1;
	while (!q.empty()) {
		int cx, cy, broke;
		tie(cx, cy, broke) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!inrange(nx, ny)) continue;
			
			//벽을 더 부술 수 있는 경우
			if (broke < k) {
				if (arr[nx][ny] == 1 && c[nx][ny][broke + 1] == -1) {
					c[nx][ny][broke + 1] = c[cx][cy][broke] + 1;
					q.push({ nx,ny,broke + 1 });
				}
			}
			//벽을 부수지 않고 이동하는 경우
			if (arr[nx][ny] == 0 && c[nx][ny][broke] == -1) {
				c[nx][ny][broke] = c[cx][cy][broke] + 1;
				q.push({ nx,ny,broke });
			}
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i <= k; i++) {
		int val = c[n - 1][m - 1][i];
		if (val != -1) ans = min(ans, val);
	}

	if (ans == INT_MAX) cout << -1;
	else cout << ans;

	return 0;
}