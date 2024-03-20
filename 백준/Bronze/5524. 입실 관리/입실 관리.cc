#include<iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		for (auto x : s) cout << char(tolower(x));
		cout << '\n';
	}
	return 0;
}