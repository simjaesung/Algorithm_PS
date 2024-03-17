#include<iostream>
using namespace std;
int arr[1005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (arr[i]) continue;

		for (int j = i; j <= n; j += i) {
			if (arr[j]) continue;
			arr[j] = 1; cnt++;
			if (cnt == k) {
				cout << j;
				return 0;
			}
		}
	}
	
	return 0;
}