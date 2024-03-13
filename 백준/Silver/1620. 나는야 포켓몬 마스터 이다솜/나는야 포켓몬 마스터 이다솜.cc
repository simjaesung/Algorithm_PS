#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

int isnum(string s) {
	char num[] = { '0','1','2','3','4','5','6','7','8','9' };
	int check = 0;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < sizeof(num); j++) {
			if (s[i] == num[j]) return 1;
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;

	vector<string>v;
	map<string, int>mm;
	int se = 1;
	while (n--) {
		string s; cin >> s;
		mm[s] = se++;
		v.push_back(s);
	}

	while (m--) {
		string s; cin >> s;
		if (isnum(s)) cout << v[stoi(s) - 1] << '\n';
		else cout << mm[s] << '\n';
	}
	return 0;
}