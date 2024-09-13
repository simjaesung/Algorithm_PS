#include<iostream>
#include<algorithm>
using namespace std;
int arr[100005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int ans = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		ans = max(ans, arr[i] * (n - i));
	}

	cout << ans;
	return 0;
}