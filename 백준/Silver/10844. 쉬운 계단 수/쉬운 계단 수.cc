#include<iostream>

using namespace std;

long long D[101][10] = { {0,1,1,1,1,1,1,1,1,1}, };

int main()
{
	int n;
	cin >> n;

	long long ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) D[i][j] = D[i - 1][j + 1];
			else if (j == 9) D[i][j] = D[i - 1][j - 1];
			else D[i][j] = D[i - 1][j - 1] + D[i - 1][j + 1];

			D[i][j] %= 1000000000;
		}
	}

	for (int i = 0; i < 10; i++)
		ans += D[n - 1][i];

	cout << ans % 1000000000;
	
	return 0;
}