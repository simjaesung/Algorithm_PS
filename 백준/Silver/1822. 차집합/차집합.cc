#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>a, b, c;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, val;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> val; a.push_back(val);
	}

	for (int i = 0; i < m; i++) {
		cin >> val; b.push_back(val);
	}

	sort(b.begin(), b.end());
	for (auto x : a) {
		if (!binary_search(b.begin(), b.end(), x)) c.push_back(x);
	}

	if (c.empty()) cout << 0;
	else {
		cout << c.size() << '\n';
		sort(c.begin(), c.end());
		for (auto x : c) cout << x << ' ';
	}
	return 0;
}