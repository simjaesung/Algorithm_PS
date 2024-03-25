#include <iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;

	int max = -1000000, min = 1000000;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;

		if (val > max) max = val;
		if (val < min) min = val;
	}

	cout << min << " " << max;

	return 0;
}