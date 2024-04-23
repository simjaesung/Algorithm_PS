#include<iostream>
#include<algorithm>
#include<queue>
#include<tuple>
#include<limits.h>
using namespace std;

int arr[5][5][5], ac[5][5][5];

int b1[5][5], b2[5][5], b3[5][5], b4[5][5], b5[5][5];
int c1[5][5], c2[5][5], c3[5][5], c4[5][5], c5[5][5];

int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

int ans = INT_MAX;

bool inrange(int x, int y, int z) {
	return x >= 0 && y >= 0 && z >= 0 && x < 5 && y < 5 && z < 5;
}

//쌓는 순서
int s[5] = { 1,2,3,4,5 };

//회전 경우
int r[4];

void bfs(int z, int x, int y)
{
	queue<tuple<int, int, int>>q;
	ac[z][x][y] = 1; q.push({ z,x,y });

	while (!q.empty()) {
		int cz = get<0>(q.front());
		int cx = get<1>(q.front());
		int cy = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = cz + dz[i];
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (inrange(nx, ny, nz) && arr[nz][nx][ny] == 1) {
				if (ac[nz][nx][ny] == 0) {
					ac[nz][nx][ny] = ac[cz][cx][cy] + 1;
					q.push(make_tuple(nz, nx, ny));
				}
			}
		}
	}
}

void r0(int b) 
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (b == 1) {
				if (b1[i][j] == 1) c1[i][j] = 1;
				else c1[i][j] = 0;
			}
			if (b == 2) {
				if (b2[i][j] == 1) c2[i][j] = 1;
				else c2[i][j] = 0;
			}
			if (b == 3) {
				if (b3[i][j] == 1) c3[i][j] = 1;
				else c3[i][j] = 0;
			}
			if (b == 4) {
				if (b4[i][j] == 1) c4[i][j] = 1;
				else c4[i][j] = 0;
			}
			if (b == 5) {
				if (b5[i][j] == 1) c5[i][j] = 1;
				else c5[i][j] = 0;
			}
		}
	}
}
void r90(int b) 
{
	for (int j = 0; j < 5; j++) {
		for (int i = 4; i >= 0; i--) {
			if (b == 1) {
				if (b1[i][j] == 1) c1[j][4 - i] = 1;
				else c1[j][4 - i] = 0;
			}
			if (b == 2) {
				if (b2[i][j] == 1) c2[j][4 - i] = 1;
				else c2[j][4 - i] = 0;
			}
			if (b == 3) {
				if (b3[i][j] == 1) c3[j][4 - i] = 1;
				else c3[j][4 - i] = 0;
			}
			if (b == 4) {
				if (b4[i][j] == 1) c4[j][4 - i] = 1;
				else c4[j][4 - i] = 0;
			}
			if (b == 5) {
				if (b5[i][j] == 1) c5[j][4 - i] = 1;
				else c5[j][4 - i] = 0;
			}
		}
	}
}


void r180(int b)
{
	for (int j = 0; j < 5; j++) {
		for (int i = 4; i >= 0; i--) {
			if (b == 1) {
				if (b1[i][j] == 1) c1[4 - i][4 - j] = 1;
				else c1[4 - i][4 - j] = 0;
			}
			if (b == 2) {
				if (b2[i][j] == 1) c2[4 - i][4 - j] = 1;
				else c2[4 - i][4 - j] = 0;
			}
			if (b == 3) {
				if (b3[i][j] == 1) c3[4 - i][4 - j] = 1;
				else c3[4 - i][4 - j] = 0;
			}
			if (b == 4) {
				if (b4[i][j] == 1) c4[4 - i][4 - j] = 1;
				else c4[4 - i][4 - j] = 0;
			}
			if (b == 5) {
				if (b5[i][j] == 1) c5[4 - i][4 - j] = 1;
				else c5[4 - i][4 - j] = 0;
			}
		}
	}
}


void r270(int b)
{
	for (int j = 0; j <5; j++) {
		for (int i = 4; i >= 0; i--) {
			if (b == 1) {
				if (b1[i][j] == 1) c1[4 - j][i] = 1;
				else c1[4 - j][i] = 0;
			}
			if (b == 2) {
				if (b2[i][j] == 1) c2[4 - j][i] = 1;
				else c2[4 - j][i] = 0;
			}
			if (b == 3) {
				if (b3[i][j] == 1) c3[4 - j][i] = 1;
				else c3[4 - j][i] = 0;
			}
			if (b == 4) {
				if (b4[i][j] == 1) c4[4 - j][i] = 1;
				else c4[4 - j][i] = 0;
			}
			if (b == 5) {
				if (b5[i][j] == 1) c5[4 - j][i] = 1;
				else c5[4 - j][i] = 0;
			}
		}
	}
}

void go(int select)
{
	if (select == 5) {
		for (int i = 0; i < 5; i++) {
			//1: 그대로 2: 90도 3: 180도 4: 270도
			if (r[i] == 1) r0(i + 1);
			else if (r[i] == 2) r90(i + 1);
			else if (r[i] == 3) r180(i + 1);
			else r270(i + 1);
		}

		do {
			//판 쌓는 순서를 정함
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					for (int k = 0; k < 5; k++) {
						if (i == 0) arr[s[i] - 1][j][k] = c1[j][k];
						if (i == 1) arr[s[i] - 1][j][k] = c2[j][k];
						if (i == 2) arr[s[i] - 1][j][k] = c3[j][k];
						if (i == 3) arr[s[i] - 1][j][k] = c4[j][k];
						if (i == 4) arr[s[i] - 1][j][k] = c5[j][k];
					}
				}
			}


			if (arr[0][0][0] == 1) {
				bfs(0, 0, 0);
				if (ac[4][4][4] != 0) ans = min(ans, ac[4][4][4]);
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						fill(ac[i][j], ac[i][j] + 5, 0);
					}
				}
			}

			if (arr[0][0][4] == 1) {
				bfs(0, 0, 4);
				if (ac[4][4][0] != 0) ans = min(ans, ac[4][4][0]);
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						fill(ac[i][j], ac[i][j] + 5, 0);
					}
				}
			}

			if (arr[0][4][0] == 1) {
				bfs(0, 4, 0);
				if (ac[4][0][4] != 0) ans = min(ans, ac[4][0][4]);
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						fill(ac[i][j], ac[i][j] + 5, 0);
					}
				}
			}

			if (arr[0][4][4] == 1 && arr[4][0][0] == 1) {
				bfs(0, 4, 4);
				if (ac[4][0][0] != 0) ans = min(ans, ac[4][0][0]);
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						fill(ac[i][j], ac[i][j] + 5, 0);
					}
				}
			}
			
		} while (next_permutation(s, s + 5));
		return;
	}

	for (int i = 1; i <= 4; i++) {
		r[select] = i;
		go(select + 1);
	}
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (i == 0) cin >> b1[j][k];
				if (i == 1) cin >> b2[j][k];
				if (i == 2) cin >> b3[j][k];
				if (i == 3) cin >> b4[j][k];
				if (i == 4) cin >> b5[j][k];
			}
		}
	}
	go(0);
	if(ans == INT_MAX) cout << -1;
	else cout << ans - 1;
	
	return 0;
}