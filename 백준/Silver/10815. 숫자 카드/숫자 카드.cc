#include<iostream>
using namespace std;

int arr[20000005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while (n--) {
		int c; cin >> c;
		arr[c + 10000000] = 1;
	}

	int m; cin >> m;
	while (m--) {
		int c; cin >> c;
		if (arr[c + 10000000] == 1) cout << 1 << ' ';
		else cout << 0 << ' ';
	}

	return 0;
}