#include<iostream>
#include<algorithm>
using namespace std;

int arr[1005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = n-1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) swap(arr[i], arr[j]);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}

	
	return 0;
}