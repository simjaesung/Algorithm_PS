#include<iostream>
using namespace std;

int main()
{
	char m[] = { 'a','e','i','o','u' };
	string s; cin >> s;
	int ans = 0;
	for (auto x : s) {
		for (int i = 0; i < 5; i++) {
			if (x == m[i]) ans++;
		}
	}
	cout << ans;
	return 0;
}