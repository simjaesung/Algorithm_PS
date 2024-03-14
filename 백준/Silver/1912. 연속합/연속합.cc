#include<iostream>
using namespace std;
int arr[100005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int ans = -1000;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i != 0 && arr[i] < arr[i - 1] + arr[i]) arr[i] += arr[i - 1];
		ans = max(ans, arr[i]);
	}	
	cout << ans;	
	return 0;
}