#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>>v;
vector<int>ans;
int val, tmp;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first > b.first;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 8; i++) {
		cin >> val;
		v.push_back(make_pair(val, i + 1));
	}

	sort(v.begin(), v.end(),compare);

	for (int i = 0; i < 5; i++) {
		tmp += v[i].first;
		ans.push_back(v[i].second);
	}

	sort(ans.begin(), ans.end());
	cout << tmp << '\n';
	for (auto x : ans) cout << x << ' ';
	return 0;
}