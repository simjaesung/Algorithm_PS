#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) cout << '*';
		for (int k = 1; k <= 2 * (n - i); k++) cout << ' ';
		for (int j = 1; j <= i; j++) cout << '*';

		cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) cout << '*';
		for (int k = 1; k <= i * 2; k++) cout << ' ';
		for (int j = 1; j <= n - i; j++) cout << '*';

		cout << '\n';
	}

	return 0;
}