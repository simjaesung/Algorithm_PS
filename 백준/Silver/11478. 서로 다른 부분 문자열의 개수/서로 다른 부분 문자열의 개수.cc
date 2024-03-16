#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int ans = 0;
	map<string, int>m;
	for (int i = 0; i < s.length(); i++) {
		string t; 
		for (int j = i; j < s.length(); j++) {
			t += s[j];
			if (!m[t]) {
				m[t] = 1; ans++;
			}
		}
	}
	cout << ans;
	return 0;
}