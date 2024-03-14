#include <iostream>
using namespace std;

long long D[201][201] = { 0 };

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= 200; i++) D[1][i] = i;

	for (int i = 2; i <= 200; i++) {
		D[i][1] = 1;
		for (int j = 2; j <= 200; j++) {
			D[i][j] = (D[i][j - 1] + D[i - 1][j]) % 1000000000;
		}
	}
	
	cout << D[n][k];
	
	return 0;
}