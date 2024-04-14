#include<iostream>
using namespace std;

int d[1000005][2];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	for (int i = 2; i <= n; i++) {
		d[i][0] = d[i - 1][0] + 1;
		d[i][1] = i - 1;
		if (i % 2 == 0) {
			if (d[i][0] > d[i / 2][0] + 1) {
				d[i][0] = d[i / 2][0] + 1;
				d[i][1] = i / 2;
			}
		}

		if (i % 3 == 0) {
			if (d[i][0] > d[i / 3][0] + 1) {
				d[i][0] = d[i / 3][0] + 1;
				d[i][1] = i / 3;
			}
		}
	}

	cout << d[n][0] << '\n';

	while (n > 0) {
		cout << n << ' ';
		n = d[n][1];
	}

	return 0;
}