#include<iostream>
using namespace std;

int isNum(char s) {
	char num[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	for (int i = 0; i < 10; i++)
		if (s == num[i]) return 1;
	return 0;
}

int main()
{
	string s; int n;
	cin >> s >> n;
	int ans = 0, val = 1;

	for (int i = s.length() - 1; i >= 0; i--) {
		if (isNum(s[i])) ans += (s[i] - '0') * val;
		else ans += (s[i] - 'A' + 10) * val;

		val *= n;
	}
	cout << ans;
	
	return 0;
}