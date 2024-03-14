#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	for (int i = 1; i <= 1000000; i++) {
		int m = i, k = i;
		while (m > 0) {
			k += m % 10;
			m /= 10;
		}
		if (k == n) {
			cout << i;
			return 0;
		}
	}

	cout << 0;
	return 0;
}