#include<iostream>
#include<limits.h>
using namespace std;
int arr[100005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	int ans = INT_MIN;

	for (int i = k; i <= n; i++) {
		ans = max(ans, arr[i] - arr[i - k]);
	}
	cout << ans;
	return 0;
}