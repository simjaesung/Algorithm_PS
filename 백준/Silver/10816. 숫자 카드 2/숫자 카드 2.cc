#include<iostream>
using namespace std;
int arr[20000005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		arr[val + 10000000] += 1;
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int val; cin >> val;
		cout << arr[val + 10000000] << ' ';
	}

	return 0;
}