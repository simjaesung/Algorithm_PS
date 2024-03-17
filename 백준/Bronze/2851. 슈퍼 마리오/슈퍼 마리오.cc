#include<iostream>
using namespace std;
int arr[10];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 10; i++) cin >> arr[i];

	int total = 0;
	for (int i = 0; i < 10; i++) {
		int tmp = total;
		total += arr[i];

		if (total >= 100) {
			if (total - 100 <= 100 - tmp) {
				cout << total;
				return 0;
			}
			else {
				cout << tmp;
				return 0;
			}
		}
	}
	cout << total;
	return 0;
}