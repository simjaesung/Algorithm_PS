#include<iostream>
#include<algorithm>
using namespace std;

int arr[1005];

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int ans = 0; int val = 0;
	for (int i = 0; i < n; i++) {
		val += arr[i];
		ans += val;
	}
	cout << ans;

	return 0;
}