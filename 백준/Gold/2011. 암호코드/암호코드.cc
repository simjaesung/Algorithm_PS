#include<iostream>
using namespace std;

int D[5000][2] = { 0 };

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	string lock;
	cin >> lock;
	size_t n = lock.length();

	if (lock[0] - '0' == 0) {
		cout << 0;
		return 0;
	}
	
	D[0][0] = 1;
	if (lock[0] - '0' == 1 || lock[0] - '0' == 2) D[0][1] = 1;

	for (int i = 1; i < n; i++) {
		D[i][0] = D[i - 1][0] + D[i - 1][1];

		if (lock[i] - '0' == 0) {
			if (lock[i - 1] - '0' != 2 && lock[i - 1] - '0' != 1) {
				cout << 0;
				return 0;
			}
			D[i][0] = D[i - 1][1];
		}

		if (lock[i - 1] - '0' == 2 && lock[i] - '0' > 6) D[i][0]--;
		D[i][0] %= 1000000;

		if (lock[i] - '0' == 1 || lock[i] - '0' == 2) 
			D[i][1] = (D[i - 1][0]) % 1000000;
	}

	cout << D[n-1][0] % 1000000;

	return 0;

}