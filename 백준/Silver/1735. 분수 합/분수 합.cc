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
	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;

	int ansA = a1 * b2 + b1 * a2;
	int ansB = b1 * b2;
	cout << ansA / gcd(ansA, ansB) << ' ' << ansB / gcd(ansA, ansB);
	return 0;
}