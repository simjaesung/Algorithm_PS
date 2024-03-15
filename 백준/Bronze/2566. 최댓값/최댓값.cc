#include<iostream>
using namespace std;

int arr[10][10];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) cin >> arr[i][j];
	}

	int max = 0;
	int x, y;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr[i][j] >= max) {
				max = arr[i][j];
				x = i; y = j;
			}
		}
	}

	cout << max << '\n' << x + 1 << ' ' << y + 1;
	
	return 0;
}