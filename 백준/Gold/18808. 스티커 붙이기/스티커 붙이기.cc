#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;
int n, m, k;
int a, b; //스티커 가로 세로
int note[45][45];
int st1[15][15], st2[15][15], st3[15][15], st4[15][15];

bool inrange(int x, int y) {
	return x >= 0 && x + a <= n && y >= 0 && y + b <= m;
}

int overlap(int x, int y,int c) {
	for (int i = x; i < x + a; i++) {
		for (int j = y; j < y + b; j++) {
			if (c == 1) {
				if ((note[i][j] + st1[i - x][j - y]) > 1) return 0;
			}
			else if (c == 2) {
				if ((note[i][j] + st2[i - x][j - y]) > 1) return 0;
			}
			else if (c == 3) {
				if ((note[i][j] + st3[i - x][j - y]) > 1) return 0;
			}
			else if (c == 4) {
				if ((note[i][j] + st4[i - x][j - y]) > 1) return 0;
			}
		}
	}
	return 1;
}

void attach(int x, int y, int c) {
	for (int i = x; i < x + a; i++) {
		for (int j = y; j < y + b; j++) {
			if (c == 1) note[i][j] += st1[i - x][j - y];
			else if (c == 2) note[i][j] += st2[i - x][j - y];
			else if (c == 3) note[i][j] += st3[i - x][j - y];
			else if (c == 4) note[i][j] += st4[i - x][j - y];
		}
	}
}

//90도
void c2(int x, int y) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (st1[i][j] == 1) st2[j][abs(i - (a - 1))] = 1;
			else st2[j][abs(i - (a - 1))] = 0;
		}
	}
	swap(a, b);
}

//180도
void c3(int x, int y) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (st2[i][j] == 1) st3[j][abs(i - (a - 1))] = 1;
			else st3[j][abs(i - (a - 1))] = 0;
		}
	}
	swap(a, b);
}

//270도
void c4(int x, int y) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (st3[i][j] == 1) st4[j][abs(i - (a - 1))] = 1;
			else st4[j][abs(i - (a - 1))] = 0;
		}
	}
	swap(a, b);
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;

	while (k--) {
		for (int k = 0; k < 15; k++) {
			fill(st1[k], st1[k] + 15, 0);
			fill(st2[k], st2[k] + 15, 0);
			fill(st3[k], st3[k] + 15, 0);
			fill(st4[k], st4[k] + 15, 0);
		}

		cin >> a >> b;
		
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				cin >> st1[i][j];
			}
		}

		//0도 회전
		int first = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (inrange(i, j) && overlap(i,j,1)) {
					attach(i, j, 1);
					first = 1;
					break;
				}
			}
			if (first) break;
		}

		if (first) continue;

		//90도 회전
		int second = 0; c2(0, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (inrange(i, j) && overlap(i, j, 2)) {
					attach(i, j, 2);
					second = 1;
					break;
				}
			}
			if (second) break;
		}
		if (second) continue;

		//180도 회전
		int thir = 0; c3(0, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (inrange(i, j) && overlap(i, j,3)) {
					attach(i, j, 3);
					thir = 1;
					break;
				}
			}
			if (thir)break;
		}
		if (thir) continue;

		//270도 회전
		int four = 0; c4(0, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (inrange(i, j) && overlap(i, j, 4)) {
					attach(i, j, 4);
					four = 1;
					break;
				}
			}
			if (four)break;
		}
		if (four) continue;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (note[i][j] == 1) ans++;
		}
	}
	cout << ans;

	return 0;
}