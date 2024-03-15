#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<cmath>
using namespace std;
typedef long long ll;
ll n, val, s, e, sum, m, tmp = LLONG_MAX;
ll ans1, ans2, ans3;
vector<int>v;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val; v.push_back(val);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			s = j + 1; e = n - 1;
			sum = v[i] + v[j];
			while (s <= e) {
				m = (s + e) / 2;
				if (abs(sum + v[m]) < tmp) {
					tmp = abs(sum + v[m]);
					ans1 = v[i];
					ans2 = v[j];
					ans3 = v[m];
				}
				if (sum + v[m] < 0) s = m + 1;
				else e = m - 1;
			}
		}
	}

	cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
	return 0;
}