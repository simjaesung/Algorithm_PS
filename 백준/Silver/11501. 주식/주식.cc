#include<iostream>
using namespace std;

int arr[1000005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];

		long long ans = 0;
		long long tmp = arr[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			if (arr[i] == tmp) continue;
			else if (arr[i] < tmp) ans += tmp - arr[i];
			else tmp = arr[i];
		}
		cout << ans << '\n';
	}
	return 0;
}