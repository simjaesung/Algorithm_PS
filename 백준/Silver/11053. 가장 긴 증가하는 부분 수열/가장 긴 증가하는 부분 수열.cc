#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int n, ans = 0;
	cin >> n;

	int arr[1001] = {0};
	int num[1001];

	for (int i = 1; i <= n; i++) cin >> num[i];

	for (int i = 1; i <= n; i++) {
		arr[i] = 1;
		for (int j = 1; j < i; j++) {
			if (num[i] > num[j])
				arr[i] = max(arr[i], arr[j] + 1);
		}
		ans = max(ans, arr[i]);
	}	
	cout << ans;
	
	return 0;
}