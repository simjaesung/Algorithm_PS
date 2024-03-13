#include<iostream>
#include<math.h>
using namespace std;

int color(string s) {
	if (s == "black")return 0;
	else if (s == "brown") return 1;
	else if (s == "red") return 2;
	else if (s == "orange") return 3;
	else if (s == "yellow") return 4;
	else if (s == "green") return 5;
	else if (s == "blue") return 6;
	else if (s == "violet") return 7;
	else if (s == "grey") return 8;
	else return 9;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	long long ans = 0;
	for (int i = 0; i < 3; i++) {
		string s; cin >> s;
		if (i == 0) ans += color(s) * 10;
		else if (i == 1) ans += color(s);
		else if (i == 2) ans *= pow(10, color(s));
	}
	cout << ans;
	return 0;
}