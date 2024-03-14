#include<iostream>
using namespace std;
int arr[1005][1005], d[1005][1005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0) d[i][j] = arr[i][j];
			else {
				int a = d[i - 1][j - 1];
				int b = d[i][j - 1];
				int c = d[i - 1][j];
				if (arr[i][j] == 0) d[i][j] = arr[i][j];
				else if (a == 0 || b == 0 || c == 0) d[i][j] = arr[i][j];
				else if (a == b && b == c) d[i][j] = a + 1;
				else d[i][j] = min(a, min(b, c)) + 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) ans = max(ans, d[i][j]);
	}
	cout << ans * ans;
	
	return 0;
}