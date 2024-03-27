#include<iostream>
using namespace std;

int arr[2005], d[2005][2005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		for (int j = i; j > 0; j--) {
			if (i == j) d[j][i] = 1;
			else {
				if (arr[i] == arr[j]) {
					if (i == j + 1) d[j][i] = 1;
					if (d[j + 1][i - 1]) d[j][i] = 1;
				}
			}
		}
	}

	int m; cin >> m;
	while (m--) {
		int i, j; cin >> i >> j;
		cout << d[i][j] <<'\n';
	}
	return 0;
}