#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll>ab; vector<ll>cd;
ll n, ans;
ll a[4005], b[4005], c[4005], d[4005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll va, vb, vc, vd;
		cin >> va >> vb >> vc >> vd;
		a[i] = va; b[i] = vb;
		c[i] = vc; d[i] = vd;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab.push_back(a[i] + b[j]);
			cd.push_back(c[i] + d[j]);
		}
	}
	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	for (auto x : ab) {
		int idx1 = lower_bound(cd.begin(), cd.end(), x * -1) - cd.begin();
		int idx2 = upper_bound(cd.begin(), cd.end(), x * -1) - cd.begin();
		ans += idx2 - idx1;
	}
	cout << ans;

	return 0;
}