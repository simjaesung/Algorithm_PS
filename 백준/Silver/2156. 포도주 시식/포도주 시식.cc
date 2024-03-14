#include<iostream>

using namespace std;
int g[10001];
int d[10001] = { 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int n, ans = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> g[i];

	d[1] = g[1];
	d[2] = g[1] + g[2];

	ans = max(d[1], d[2]);

	for (int i = 3; i <= n; i++) {
		d[i] = max(d[i - 1], max(d[i - 2] + g[i], d[i - 3] + g[i] + g[i - 1]));
		ans = max(ans, d[i]);
	}

	cout << ans;
	return 0;
}