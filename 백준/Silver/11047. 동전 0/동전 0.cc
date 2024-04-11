#include<iostream>
using namespace std;
int arr[15];

int main()
{
	int n, k; cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] <= k) {
			while (arr[i] <= k) {
				k -= arr[i];
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}