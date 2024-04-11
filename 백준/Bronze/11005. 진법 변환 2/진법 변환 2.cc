#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, b;
	cin >> n >> b;

	char alpha[26];
	for (int i = 0; i < 26; i++) alpha[i] = 'A' + i;
	string s;
	while (n >= b) {
		int k = n % b;
		if (k > 9) s += alpha[k - 10];
		else s += to_string(k);
		n /= b;
	}
	if (n > 9) s += alpha[n - 10];
	else s += to_string(n);

	for (int i = s.length() - 1; i >= 0; i--)
		cout << s[i];

	return 0;
}