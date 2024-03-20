#include<iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while (n--) {
		long long a, b;
		cin >> a >> b;
		cout << a / gcd(a, b) * b << '\n';
	}
	return 0;
}