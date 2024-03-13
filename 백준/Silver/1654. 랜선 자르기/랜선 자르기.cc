#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int k, n, val;
vector<int>v;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> val; v.push_back(val);
	}
	sort(v.begin(), v.end());

	ll s = 1, e = v[k - 1], ans = 0;
	while (s <= e) {
		ll m = (s + e) / 2;
		
		int cnt = 0;
		for (int i = 0; i < k; i++) cnt += v[i] / m;

		if (cnt < n) e = m - 1;
		else {
			ans = m;
			s = m + 1;
		}
	}

	cout << ans;
	
	return 0;
}