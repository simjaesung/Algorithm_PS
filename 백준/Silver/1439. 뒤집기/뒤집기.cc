#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int a = 0, b = 0; //0 , 1
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] != s[i + 1]) {
			if (s[i] == '0') a++;
			else b++;
		}
	}
	if (s[s.length() - 1] == '0') a++;
	else b++;

	cout << min(a, b);

	return 0;
}