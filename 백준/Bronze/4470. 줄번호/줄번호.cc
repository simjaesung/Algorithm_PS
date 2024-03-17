#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	cin.ignore();
	int val = 1;
	while (val <= n) {
		string s; getline(cin, s);

		cout << val << ". " << s << '\n';
		val++;
	}
	return 0;
}