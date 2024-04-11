#include<iostream>
using namespace std;

int arr[10005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	while (n--) {
		int val; cin >> val;
		arr[val]++;
	}

	for (int i = 1; i <= 10000; i++) {
		while (arr[i]--) {
			cout << i << '\n';
		}
	}

	return 0;
}