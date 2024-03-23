#include<iostream>
using namespace std;
long long arr[105];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	arr[1] = 1; arr[2] = 1;
	for (int i = 3; i <= 100; i++) {
		arr[i] = arr[i - 3] + arr[i - 2];
	}

	int n; cin >> n;
	while (n--) {
		int val; cin >> val;
		cout << arr[val] << '\n';
	}

	return 0;
}