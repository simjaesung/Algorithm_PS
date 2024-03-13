#include<iostream>
using namespace std;
int main()
{
	int ans = 0;
	for (int i = 0; i < 8; i++) {
		string s; cin >> s;
		if (i % 2 == 0) {
			if (s[0] == 'F') ans++;
			if (s[2] == 'F') ans++;
			if (s[4] == 'F') ans++;
			if (s[6] == 'F') ans++;
		}
		else {
			if (s[1] == 'F') ans++;
			if (s[3] == 'F') ans++;
			if (s[5] == 'F') ans++;
			if (s[7] == 'F') ans++;
		}
	}
	cout << ans;
	
	return 0;
}