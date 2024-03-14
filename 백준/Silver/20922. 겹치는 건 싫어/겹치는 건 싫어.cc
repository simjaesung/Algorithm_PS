#include<iostream>
using namespace std;
int n, k, s, e, ans; 
int arr[200005], c[100005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];

	while (s < n && e < n) {
		if (c[arr[e]] < k) c[arr[e++]]++;
		else c[arr[s++]]--;
		ans = max(ans, e - s);
	}

	cout << ans;

	return 0;
}