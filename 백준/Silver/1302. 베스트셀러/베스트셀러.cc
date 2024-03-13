#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<string,int>a, pair<string,int>b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	vector<pair<string, int>>v;

	while (n--) {
		string s; cin >> s;
		int check = 0;
		for (int i = 0; i < v.size(); i++) {
			if (s == v[i].first) {
				check = 1;
				v[i].second++;
				break;
			}
		}
		if (!check) v.push_back({ s, 1 });
	}

	sort(v.begin(), v.end(), compare);
	cout << v[0].first;
	
	return 0;
}