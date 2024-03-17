#include<iostream>
using namespace std;
int arr[1005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans = 0, tmp = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i - 1]) tmp += arr[i] - arr[i - 1];
		else {
			ans = max(ans, tmp);
			tmp = 0;
		}
	}
	cout << max(ans, tmp);

	return 0;
}