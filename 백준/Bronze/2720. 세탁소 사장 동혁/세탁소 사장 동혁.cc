#include<iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while (n--) {
		int ans[4] = { 0 };
		int val; cin >> val;

		if (val >= 25) {
			while (val >= 25) {
				ans[0]++;
				val -= 25;
			}
		}

		if (val >= 10) {
			while (val >= 10) {
				ans[1]++;
				val -= 10;
			}
		}

		if (val >= 5) {
			while (val >= 5) {
				ans[2]++;
				val -= 5;
			}
		}

		if (val >= 1) {
			while (val >= 1) {
				ans[3]++;
				val -= 1;
			}
		}
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}