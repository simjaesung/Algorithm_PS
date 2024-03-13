#include<iostream>
using namespace std;

int arr[55];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int val1 = arr[0];
	int val2 = arr[0];
	for (int i = 1; i < n; i++) {
		val1 = max(val1, arr[i]);
		val2 = min(val2, arr[i]);
	}

	while (1) {
		val1 *= val2;
		int check = 0;
		for (int i = 0; i < n; i++) {
			if (val1 % arr[i] != 0) {
				check = 1; break;
			}
		}

		if (!check) break;
	}
	cout << val1;
	
	return 0;
}