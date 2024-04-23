#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;

int n, m, ans = INT_MAX;
bool inrange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int arr[55][55];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	vector<pair<int, int>>v; //바이러스 목록
	vector<int>vh; //활성화된 바이러스 택

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) v.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < m; i++) vh.push_back(0);
	for (int i = 0; i < v.size()-m; i++) vh.push_back(1);
	
	do {
		int c[55][55] = { 0, };

		queue<pair<int, int>>q;

		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;
			if (vh[i] == 0) {
				q.push(make_pair(x, y));
				c[x][y] = 1;
			}
		}

		while (!q.empty()) {
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (!inrange(nx, ny)) continue;
				if (arr[nx][ny] == 1) continue;
				if (c[nx][ny] != 0) continue;

				c[nx][ny] = c[cx][cy] + 1;
				q.push(make_pair(nx, ny));
				
			}
		}

		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;
			if (vh[i] == 1) c[x][y] = -1;
		}

		int val = -1, check = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				val = max(val, c[i][j] - 1);
				if (arr[i][j] != 1 && c[i][j] == 0) check = 1;
			}
		}

		if (!check) ans = min(ans, val);

	} while (next_permutation(vh.begin(), vh.end()));

	if (ans == INT_MAX) cout << -1;
	else cout << ans;
	return 0;
}