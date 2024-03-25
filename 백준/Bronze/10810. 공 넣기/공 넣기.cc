#include<iostream>
using namespace std;

int arr[105];

int main()
{
	int n, m;
	cin >> n >> m;

	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;

		for (int s = i; s <= j; s++) arr[s] = k;
	}

	for (int i = 1; i <= n; i++) cout << arr[i] << ' ';

	return 0;
}