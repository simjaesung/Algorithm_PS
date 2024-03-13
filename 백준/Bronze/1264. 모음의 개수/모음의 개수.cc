#include<iostream>
#include<string>
using namespace std;

int main()
{
	char mo[] = { 'a','e','i','o','u','A','E','I','O','U'};

	while (1) {
		string s; 
		getline(cin, s);
		if (s == "#") break;

		int ans = 0;
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < 10; j++) {
				if (mo[j] == s[i]) ans++;
			}
		}
		cout << ans << '\n';
	}
	
	
	return 0;
}