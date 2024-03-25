#include<iostream>
using namespace std;

int n;
char arr[101][101];
int c1[101][101], c2[101][101];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int inrange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n)return 1;
	return 0;
}

void dfs1(int x, int y, int cnt, char s)
{
	c1[x][y] = cnt;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (inrange(nx, ny)) {
			if (arr[nx][ny] == s && c1[nx][ny] == 0) {
				dfs1(nx, ny, cnt, s);
			}
		}
	}
}

void dfs2(int x, int y, int cnt, char s)
{
	c2[x][y] = cnt;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (inrange(nx, ny) && c2[nx][ny] == 0) {
			if (s == 'R' || s == 'G') {
				if (arr[nx][ny] == 'R' || arr[nx][ny] == 'G') {
					dfs2(nx, ny, cnt, s);
				}
			}
			else {
				if (arr[nx][ny] == s) dfs2(nx, ny, cnt, s);
			}
			
		}
	}
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for(int i = 0; i<n; i++){
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j];
		}
	}

	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c1[i][j] == 0) dfs1(i, j, ++cnt1, arr[i][j]);
			if (c2[i][j] == 0) dfs2(i, j, ++cnt2, arr[i][j]);
		}
	}

	cout << cnt1 << ' ' << cnt2;

	return 0;
}