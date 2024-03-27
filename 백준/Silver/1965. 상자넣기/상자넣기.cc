#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000005], d[1000005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	d[0] = arr[0];
	int k = 0;
	for (int i = 1; i < n; i++) {
		if (d[k] < arr[i]) {
			d[k + 1] = arr[i];
			k++;
		}
		else {
			int idx = lower_bound(d, d + k + 1, arr[i]) - d;
			d[idx] = arr[i];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) if (d[i] != 0)ans++;
	cout << ans;
	return 0;
}