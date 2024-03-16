#include<iostream>
#include<map>
#include<vector>
using namespace std;

map<string, int>m;
vector<string>v;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while (n--) {
		string n, s;
		cin >> n >> s;
		if (s == "enter") m[n] = 1;
		else m[n] = 0;
	}

	for (auto x : m) if (x.second) v.push_back(x.first);

	for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << '\n';
	
	return 0;
}