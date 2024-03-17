#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int arr[3];
	for (int i = 0; i < 3; i++) cin >> arr[i];

	for (int i = 2; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[i]) {
				swap(arr[j], arr[i]);
			}
		}
	}

	for (int i = 0; i < 3; i++) cout << arr[i] << ' ';
	
	return 0;
}