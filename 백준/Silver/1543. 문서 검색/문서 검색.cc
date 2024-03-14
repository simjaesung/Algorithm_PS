#include<iostream>
#include<string>
using namespace std;
string s, k;
int ans;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	getline(cin, s);
	getline(cin, k);
	if (k.length() > s.length()) {
		cout << 0; return 0;
	}
	for (int i = 0; i <= s.length() - k.length(); i++) {
		int check = 0;
		for (int j = 0; j < k.length(); j++) {
			if (s[i + j] != k[j]) check = 1;
		}
		if (!check) {
			ans++;
			i = i + k.length() - 1;
		}
	}
	cout << ans;
	return 0;
}