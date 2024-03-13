#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	int s = 0; int ans = 0;
	while (1) {
		if (ans == n) break;
		int tmp = ++s;
		while (tmp > 0) {
			if (tmp % 1000 == 666) {
				ans++; break;
			}
			tmp /= 10;
		}
	}

	cout << s;
	
	return 0;
}