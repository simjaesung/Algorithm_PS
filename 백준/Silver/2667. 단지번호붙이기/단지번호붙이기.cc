#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[30][30], c[30][30];
int n;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int inrange(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) return 1;
	return 0;
}

void dfs(int x, int y, int cnt)
{
	c[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (inrange(next_x, next_y)) {
			if (arr[next_x][next_y] == 1 && c[next_x][next_y] == 0)
				dfs(next_x, next_y, cnt);
		}
	}
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++)
			arr[i][j] = s[j] - '0';
	}		

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && c[i][j] == 0)
				dfs(i, j, ++cnt);
		}
	}

	cout << cnt << '\n';

	vector<int>v(cnt);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i][j] != 0) v[c[i][j] - 1]++;
		}
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < cnt; i++) cout << v[i] << '\n';

	return 0;
}