#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<string>v;
vector<string>ans;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		string f; cin >> f;
		int idx = lower_bound(v.begin(), v.end(), f) - v.begin();
		
		if (v[idx] == f) ans.push_back(f);
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto x : ans) cout << x << '\n';
	
	return 0;
}