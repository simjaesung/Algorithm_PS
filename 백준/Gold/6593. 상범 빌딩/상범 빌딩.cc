#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;

int l, r, c;
char b[31][31][31];
int v[31][31][31];

int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

int inrange(int z, int x, int y) {
	if (z >= 0 && z < l && x >= 0 && x < r && y >= 0 && y < c) return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	while (1) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;
		for (int i = 0; i < 31; i++) {
			for (int j = 0; j < 31; j++) {
				fill(v[i][j], v[i][j] + 31, 0);
			}
			
		}
		queue<tuple<int, int, int>>q;

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				string s; cin >> s;
				for (int k = 0; k < s.length(); k++) {
					b[i][j][k] = s[k];
					if (b[i][j][k] == 'S') q.push(make_tuple(i, j, k));
				}
			}
		}

		int ans = -1;

		while (!q.empty()) {
			int cz = get<0>(q.front());
			int cx = get<1>(q.front());
			int cy = get<2>(q.front());
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nz = cz + dz[i];
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (inrange(nz, nx, ny)) {
					//가려는 곳이 금일 경우
					if (b[nz][nx][ny] == '#') continue;
					//갈 수 있는 경우
					if (b[nz][nx][ny] == '.' && v[nz][nx][ny] == 0) {
						v[nz][nx][ny] = v[cz][cx][cy] + 1;
						b[nz][nx][ny] = 'S';
						q.push(make_tuple(nz, nx, ny));
					}
					//출구일 경우
					if (b[nz][nx][ny] == 'E') {
						v[nz][nx][ny] = v[cz][cx][cy] + 1;
						ans = v[nz][nx][ny];
						q.push(make_tuple(nz, nx, ny));
					}
				}
			}

		}
		if (ans != -1) cout << "Escaped in " << ans << " minute(s).\n";
		else cout << "Trapped!\n";
	}
	return 0;
}