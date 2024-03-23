#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	cin.ignore();

	while (t--) {
		string s;
		getline(cin, s);
		
		vector<string>v;
		string tmp;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				v.push_back(tmp);
				tmp.clear();
			}
			else  tmp += s[i];
		}
		v.push_back(tmp);

		for (auto x : v) {
			for (int i = 0; i < x.length() / 2; i++) {
				swap(x[i], x[x.length() - i - 1]);
			}
			cout << x << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}