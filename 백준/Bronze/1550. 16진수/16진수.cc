#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int val = 1,ans = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (isalpha(s[i])) ans += (s[i] - 55) * val;
		else ans += (s[i] - 48) * val;
		val *= 16;
	}
	cout << ans;
	
	return 0;
}