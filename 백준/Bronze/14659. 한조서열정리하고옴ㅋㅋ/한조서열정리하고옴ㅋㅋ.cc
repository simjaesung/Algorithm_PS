#include<iostream>
using namespace std;
int arr[30005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans = 0, val = 0, m = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] < m) val++;
		else {
			ans = max(ans, val);
			val = 0;
			m = arr[i];
		}
	}
	cout << max(ans,val);
	return 0;
}