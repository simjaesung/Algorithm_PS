#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

char space[1005][1005];
int v[1005][1005];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int w, h;

int inrange(int x, int y){
	if (x >= 0 && x < h && y >= 0 && y < w) return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	
	while (t--) {
		//이전 테케 방문기록 초기화
		for (int i = 0; i < 1005; i++)	
			fill(v[i], v[i] + 1005, 0);

		cin >> w >> h;
		int ans = -1;
		queue<pair<int,int>>q;

		for (int i = 0; i < h; i++) {
			string s; cin >> s;
			for (int j = 0; j < s.length(); j++) {
				space[i][j] = s[j];
				if (s[j] == '@') q.push(make_pair(i, j));
			}	
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				//상근이가 먼저 도망가야함
				if (space[i][j] == '*') q.push(make_pair(i, j));
			}
		}

		int find = 0;
		while (!q.empty()) {
			if (find) break;
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (inrange(nx, ny)) {
					//가려는 곳이 벽일 경우
					if (space[nx][ny] == '#') continue;

					//상근이일 경우
					else if (space[cx][cy] == '@') {
						if (space[nx][ny] == '.') {
							space[nx][ny] = '@';
							v[nx][ny] = v[cx][cy] + 1;
							q.push(make_pair(nx, ny));
						}
					}
					//불일 경우
					else if (space[cx][cy] == '*') {
						if (space[nx][ny] != '*') {
							q.push(make_pair(nx, ny));
							space[nx][ny] = '*';
						}
					}
				}
				else {
					//공간을 벗어나려는게 상근이일 경우
					if (space[cx][cy] == '@') {
						ans = v[cx][cy] + 1;
						find = 1; break;
					}
					
				}
			}
		}

		if (ans == -1)cout << "IMPOSSIBLE\n";
		else cout << ans << '\n';
	}


	return 0;
}