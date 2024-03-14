#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int arr[1005][1005];
int v_start[1005][1005];
int v_end[1005][1005];
int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int inrange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++)
			arr[i][j] = s[j] - '0';
	}

	queue<pair<int, int>>q1;
	queue<pair<int, int>>q2;
	
	//시작점부터 bfs
	q1.push(make_pair(0, 0)); v_start[0][0] = 1;
	//끝점부터 bfs
	q2.push(make_pair(n - 1, m - 1)); v_end[n - 1][m - 1] = 1;

	//시작점 bfs
	while (!q1.empty()) {
		int cx = q1.front().first;
		int cy = q1.front().second;
		q1.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (inrange(nx, ny)) {
				if (arr[nx][ny] == 0 && v_start[nx][ny] == 0) {
					v_start[nx][ny] = v_start[cx][cy] + 1;
					q1.push(make_pair(nx, ny));
				}
			}
		}
	}

	//끝점 bfs
	while (!q2.empty()) {
		int cx = q2.front().first;
		int cy = q2.front().second;
		q2.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (inrange(nx, ny)) {
				if (arr[nx][ny] == 0 && v_end[nx][ny] == 0) {
					v_end[nx][ny] = v_end[cx][cy] + 1;
					q2.push(make_pair(nx, ny));
				}
			}
		}
	}
	
	vector<int>ans;
	//벽 부시고 연결이 될 때
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//벽일 경우
			if (arr[i][j] == 1) {
				//상하
				if (inrange(i - 1, j) && inrange(i + 1, j)) {
					if (v_start[i - 1][j] > 0 && v_end[i + 1][j] > 0) {
						ans.push_back(v_start[i - 1][j] + v_end[i + 1][j] + 1);
					}
					if (v_start[i + 1][j] > 0 && v_end[i - 1][j] > 0) {
						ans.push_back(v_start[i + 1][j] + v_end[i - 1][j] + 1);
					}
				}
				//좌우
				if (inrange(i, j - 1) && inrange(i, j + 1)) {
					if (v_start[i][j - 1] > 0 && v_end[i][j + 1] > 0) {
						ans.push_back(v_start[i][j - 1] + v_end[i][j + 1] + 1);
					}
					if (v_start[i][j + 1] > 0 && v_end[i][j - 1] > 0) {
						ans.push_back(v_start[i][j + 1] + v_end[i][j - 1] + 1);
					}
				}
			}
		}
	}

	//벽을 부시고 시작 끝으로 갈 수 있는 경우
	if (!ans.empty()) {
		int x = ans[0];
		for (auto s : ans) x = min(x, s);
		if (v_end[0][0] == 0) cout << x;
		else {
			if (v_end[0][0] > x) cout << x;
			else cout << v_end[0][0];
		}
	}
	//벽을 부시고 시작 끝으로 갈 수 없는 경우
	else {
		if (v_end[0][0] == 0) cout << -1;
		else cout << v_end[0][0];
	}
	
	return 0;
}
