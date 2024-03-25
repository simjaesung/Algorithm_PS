#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b){
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	vector<pair<int, string>>v;

	for (int i = 0; i < n; i++) {
		int a; string s;
		cin >> a >> s;
		v.push_back(make_pair(a, s));
	}


	stable_sort(v.begin(), v.end(), compare);

	for (auto x : v) cout << x.first << ' ' << x.second << '\n';

	return 0;
}