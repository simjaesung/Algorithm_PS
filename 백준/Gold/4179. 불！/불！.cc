#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int r, c;
char miro[1005][1005];
int JI[1005][1005];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int inrange(int x, int y) {
	if (x >= 0 && x < r && y >= 0 && y < c)return 1;
	return 0;
}

int main()
{	
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> r >> c;

	queue<pair<int, int>>q;

	for (int i = 0; i < r; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			miro[i][j] = s[j];
			if (miro[i][j] == 'J') {
				q.push(make_pair(i, j));
				JI[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (miro[i][j] == '#') continue;
			if (miro[i][j] == 'F') q.push(make_pair(i, j));
		}
	}

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (inrange(nx, ny)) {
				if (miro[nx][ny] == '#') continue;
				//지나갈 수 있는 공간일 경우
				else if (miro[cx][cy] == 'J') {
					if (miro[nx][ny] == '.' && JI[nx][ny] == 0) {
						JI[nx][ny] = JI[cx][cy] + 1;
						miro[nx][ny] = 'J';
						q.push(make_pair(nx, ny));
					}
				}
				//불일 경우
				else if (miro[cx][cy] == 'F') {
					if (miro[nx][ny] == '.' || miro[nx][ny] == 'J') {
						miro[nx][ny] = 'F';
						q.push(make_pair(nx, ny));
					}
				}
			}
			else {
				if (miro[cx][cy] == 'J') {
					cout << JI[cx][cy];
					return 0;
				}
			}
		}
		if (miro[cx][cy] == 'J') miro[cx][cy] == '.';
	}
	cout << "IMPOSSIBLE";
	return 0;
}
