#include<iostream>
using namespace std;

int d[35][1005], arr[1005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t, w; cin >> t >> w;
	for (int i = 1; i <= t; i++) cin >> arr[i];

	//0번 움직였을 때
	for (int i = 1; i <= t; i++) {
		d[0][i] = d[0][i - 1];
		if (arr[i] == 1) d[0][i] += 1;
	}

	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= t; j++) {
			d[i][j] = max(d[i - 1][j - 1], d[i][j - 1]);
			if (i % 2 == 1 && arr[j] == 2) d[i][j]++;
			if (i % 2 == 0 && arr[j] == 1) d[i][j]++;
		}
	}

	int ans = 0;
	for (int i = 0; i <= w; i++) ans = max(ans, d[i][t]);
	cout << ans;

	return 0;
}