#include<iostream>
using namespace std;

int main()
{
	int arr[8];
	for (int i = 0; i < 8; i++) cin >> arr[i];

	int as = 0, des = 0;
	for (int i = 1; i < 8; i++) {
		if (arr[i] > arr[i - 1]) as = 1;
		else des = 1;

		if (as && des) {
			cout << "mixed";
			return 0;
		}
	}

	if (as) cout << "ascending";
	else cout << "descending";
	
	return 0;
}