#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> b >> a;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());
	int ans = 0, e = 0; //끝 시간
	for (auto x : v) {
		if (x.second >= e) {
			e = x.first;
			ans++;
		}
	}
	cout << ans;
	return 0;
}