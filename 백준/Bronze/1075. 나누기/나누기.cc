#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, f;
	cin >> n >> f;

	n /= 100; n *= 100;
	for (int i = 0; i < 100; i++) {
		if ((n + i) % f == 0) {
			if (i < 10) cout << 0; 
			cout << i; 
			return 0;
		}
	}
	return 0;
}