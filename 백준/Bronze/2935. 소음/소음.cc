#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string a, b, c;
	cin >> a >> b >> c;

	if (b == "*") {
		cout << "1";
		for (int i = 0; i < a.length() + c.length() - 2; i++) cout << "0";
	}
	else {
		int l = max(a.length(), c.length());
		int s = min(a.length(), c.length());

		if (l == s) {
			cout << "2";
			for (int i = 0; i < s - 1; i++) cout << "0";
		}
		else {
			cout << "1";
			for (int i = 0; i < l - s - 1; i++) cout << "0";
			cout << "1";
			for (int i = 0; i < s - 1; i++) cout << "0";
		}
	}
	
	return 0;
}