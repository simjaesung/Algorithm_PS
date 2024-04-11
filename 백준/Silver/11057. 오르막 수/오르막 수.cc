#include <iostream>

using namespace std;
int orr[1001][10];

int main()
{
	int n, ans = 0;
	cin >> n;

	for (int j = 0; j < 10; j++) orr[1][j] = 1;

	for (int i = 2; i <= n; i++) {
		orr[i][0] = 1;
		for (int j = 1; j < 10; j++) {
			orr[i][j] = (orr[i][j - 1] + orr[i - 1][j]) % 10007;
		}
	}

	for (int k = 0; k < 10; k++) ans += orr[n][k];
	cout << ans % 10007;
	
	return 0;
}