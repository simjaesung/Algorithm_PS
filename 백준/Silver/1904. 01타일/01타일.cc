#include<iostream>
using namespace std;

int arr[1000005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	arr[1] = 1; arr[2] = 2;
	for (int i = 3; i <= 1000000; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	}
	cout << arr[n];

	return 0;
}