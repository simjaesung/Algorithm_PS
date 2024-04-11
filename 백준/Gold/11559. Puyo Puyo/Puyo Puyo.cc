#include<iostream>
#include<vector>
using namespace std;

char arr[13][7];
int c1[13][7], c2[13][7];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int cnt = 0, ans = 0;

bool inrange(int x, int y) {
	return x >= 0 && x < 12 && y >= 0 && y < 6;
}


void dfs(int x, int y)
{
	c1[x][y] = 1; cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!inrange(nx, ny)) continue;
		if (arr[x][y] != arr[nx][ny]) continue;

		if (c1[nx][ny] == 0) dfs(nx, ny);
	}
}

void dfspop(int x, int y)
{
	c2[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!inrange(nx, ny)) continue;
		if (arr[x][y] != arr[nx][ny]) continue;

		if (c2[nx][ny] == 0) dfspop(nx, ny);
	}
}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 12; i++) {
		string s; cin >> s;
		for (int j = 0; j < 6; j++) {
			arr[i][j] = s[j];
		}
	}

	while (1) {
		int check = 1;

		for (int i = 0; i < 12; i++) {
			fill(c1[i], c1[i] + 6, 0);
			fill(c2[i], c2[i] + 6, 0);
		}

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				cnt = 0;
				if (arr[i][j] != '.' && c1[i][j] == 0) dfs(i, j);
				//4개 이상 동일한게 존재할 시 .으로 바꿈
				if (cnt >= 4) {
					dfspop(i, j);
					check = 0;
				}
			}
		}

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (c2[i][j] == 1) arr[i][j] = '.';
			}
		}

		if (!check) {
			ans++;
			for (int j = 0; j < 6; j++) {
				vector<char>v;
				for (int i = 11; i >= 0; i--) {
					if (arr[i][j] != '.') v.push_back(arr[i][j]);
				}
				int val = 12 - v.size();
				while (val--) v.push_back('.');

				for (int k = 0; k < 12; k++) {
					arr[11-k][j] = v[k];
				}

			}
		}
		else break;

	}

	cout << ans;
	
	return 0;
}