#include<iostream>
using namespace std;

long long r[501][501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	long long n, ans = 0;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) cin >> r[i][j];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) r[i][j] += r[i - 1][j];
			else if (j == i) r[i][j] += r[i - 1][j - 1];
			else r[i][j] += max(r[i - 1][j - 1], r[i - 1][j]);
		}
	}

	for (int i = 1; i <= n; i++)
		ans = max(ans, r[n][i]);

	cout << ans;
	
	return 0;
}