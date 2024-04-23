#include<iostream>

using namespace std;

long long gcd(long long a, long long b)
{
	while (b != 0) {
		long long r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	long long N, S, c, dis, g = 0;

	cin >> N >> S;

	while (N--) {
		cin >> c;

		if (c > S) dis = c - S;
		else dis = S - c;

		if (g == 0) g = dis;
		else g = gcd(g, dis);
	}

	cout << g;

	return 0;
}