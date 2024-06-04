#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

int n, m, val, s, e, ans = INT_MAX;
vector<int>v;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> val; v.push_back(val);
	}
	sort(v.begin(), v.end());

	while (s < n && e < n) {
		if (v[e] - v[s] < m) e++;
		else {
			ans = min(ans, v[e] - v[s]);
			s++;
		}
	}
	cout << ans;
	return 0;
}