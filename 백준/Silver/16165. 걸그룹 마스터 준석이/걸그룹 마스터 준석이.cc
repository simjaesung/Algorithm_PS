#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, cnt, num;
string group, mem, q;
unordered_map<string, string>m1;
unordered_map<string, vector<string>>m2;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	while (n--) {
		cin >> group;
		cin >> cnt;
		vector<string>v;
		while (cnt--) {
			cin >> mem;
			m1[mem] = group;
			v.push_back(mem);
		}
		sort(v.begin(), v.end());
		m2[group] = v;
	}

	while (m--) {
		cin >> q;
		cin >> num;
		if (num == 1) cout << m1[q] << '\n';
		else {
			for (auto x : m2[q]) cout << x << '\n';
		}
	}
	return 0;
}