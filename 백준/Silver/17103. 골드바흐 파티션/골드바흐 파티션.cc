#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, val, ans;
	cin >> T;

	vector<int>check(1000001);

	for (int i = 2; i <= 1000000; i++) {
		if (!check[i]) {
			for (int j = 2 * i; j <= 1000000; j += i) {
				check[j] = 1;
			}
		}
	}

	while (T--) {
		ans = 0;
		cin >> val;
		for (int i = 2; i <= val / 2; i++) {
			if (!(check[i]) && !(check[val - i])) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}