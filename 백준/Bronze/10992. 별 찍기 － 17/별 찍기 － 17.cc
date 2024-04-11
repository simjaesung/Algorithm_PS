#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= n - i; j++) cout << ' ';
		cout << '*';

		if (i > 1) {
			for (int k = 1; k <= 2 * (i - 1) -1; k++) cout << ' ';
			cout << '*';
		}

		cout << '\n';
	}
	for (int h = 1; h <= 2 * n - 1; h++) cout << '*';
	
	
	return 0;
}