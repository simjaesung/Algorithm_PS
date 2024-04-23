#include<iostream>
using namespace std;

int arr[3];
int main()
{
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	if (sum >= 100) cout << "OK";
	else {
		int minidx = 0;
		for (int i = 1; i < 3; i++) {
			if (arr[minidx] > arr[i]) minidx = i;
		}

		if (minidx == 0) cout << "Soongsil";
		else if (minidx == 1) cout << "Korea";
		else cout << "Hanyang";
	}
	return 0;
}