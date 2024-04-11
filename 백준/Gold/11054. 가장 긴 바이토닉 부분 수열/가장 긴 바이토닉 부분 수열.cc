#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int num[1001], LIS[1001], LDS[1001];

	int n, ans = 1;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> num[i];

	for (int i = 1; i <= n; i++) {
		LIS[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (num[i] > num[j]) LIS[i] = max(LIS[i], LIS[j] + 1);
		}
	}

	for (int i = n; i >= 1; i--) {
		LDS[i] = 1;
		for (int j = i + 1; j <= n; j++) {
			if (num[i] > num[j])LDS[i] = max(LDS[i], LDS[j] + 1);
		}
	}

	for (int i = 1; i <= n; i++) ans = max(ans, LIS[i] + LDS[i] - 1);

	cout << ans;

	return 0;
}