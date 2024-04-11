#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int n, ans = 0;
	cin >> n;
	
	int num[1001], LIS[1001];

	for (int i = 1; i <= n; i++) cin >> num[i];

	for (int i = 1; i <= n; i++) {
		LIS[i] = num[i];
		for (int j = 1; j < i; j++) {
			if (num[i] > num[j]) LIS[i] = max(LIS[i], LIS[j] + num[i]);
		}
		ans = max(ans, LIS[i]);
	}
	
	cout << ans;
	return 0;
}