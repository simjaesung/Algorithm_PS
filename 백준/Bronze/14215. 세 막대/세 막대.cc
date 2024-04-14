#include<iostream>
using namespace std;
int a, b, c, l, k, ans;
int main()
{
	cin >> a >> b >> c;
	l = max(a, max(b, c));
	if (a == l) {
		if (b + c > l) ans = b + c + a;
		else ans = 2 * (b + c) - 1;
	}
	else if (b == l) {
		if (a + c > l) ans = b + c + a;
		else ans = 2 * (a + c) - 1;
	}
	else {
		if (a + b > l) ans = b + c + a;
		else ans = 2 * (a + b) - 1;
	}

	cout << ans;
	
	return 0;
}