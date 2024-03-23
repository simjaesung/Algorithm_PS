#include<iostream>
#include<map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int val; cin >> val;
		map<string, int>m;
		while (val--) {
			string s1, s2;
			cin >> s1 >> s2;
			if (!m[s2]) m[s2] = 1;
			else m[s2]++;
		}
		int ans = 1;
		for (auto x : m)ans *= x.second + 1;
		cout << ans - 1 <<'\n';
	}
	
	return 0;
}