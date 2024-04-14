#include<iostream>
using namespace std;

void hanoi(int a, int b, int k)
{
	if (k == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}

	hanoi(a, 6 - a - b, k - 1);
	cout << a << ' ' << b << '\n';
	hanoi(6 - a - b, b, k - 1);
}

int main()
{
	int n; cin >> n;

	cout << (1 << n) - 1 << '\n';
	hanoi(1, 3, n);
	return 0;
}