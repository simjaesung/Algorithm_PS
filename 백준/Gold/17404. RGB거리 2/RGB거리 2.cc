#include <iostream>
using namespace std;

int arr[1001][3];
int D[1001][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++)	cin >> arr[i][j];
	}

	int ans = 1000 * 1000 + 1;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) D[1][j] = arr[1][j];
			else D[1][j] = 1000 * 1000 + 1;
		}

		for (int k = 2; k <= n; k++) {
			D[k][0] = min(D[k - 1][1], D[k - 1][2]) + arr[k][0];
			D[k][1] = min(D[k - 1][0], D[k - 1][2]) + arr[k][1];
			D[k][2] = min(D[k - 1][0], D[k - 1][1]) + arr[k][2];
		}

		for (int l = 0; l < 3; l++) {
			if (l != i) {
				ans = min(ans, D[n][l]);
			}
		}
	} 

	cout << ans;

	return 0;
}