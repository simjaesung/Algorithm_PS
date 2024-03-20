#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000005], d[1000005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) d[arr[i]] = d[arr[i] - 1] + 1;
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(d[i], ans);
	cout << n - ans;
	
	return 0;
}