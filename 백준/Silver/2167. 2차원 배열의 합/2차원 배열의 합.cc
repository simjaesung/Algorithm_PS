#include<iostream>
using namespace std;
int arr[305][305];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> arr[i][j];
	}

	int t; cin >> t;
	while (t--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans = 0;

		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) ans += arr[i][j];
		}

		cout << ans <<'\n';
	}
	return 0;
}