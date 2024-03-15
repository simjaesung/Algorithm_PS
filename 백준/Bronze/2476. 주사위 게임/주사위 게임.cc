#include<iostream>
using namespace std;
int a, b, c, n, ans, val;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n; 
	
	while (n--) {
		cin >> a >> b >> c;
		if (a == b && b == c) val = 10000 + a * 1000;
		else if (a == b && a != c) val = 1000 + a * 100;
		else if (a == c && a != b) val = 1000 + a * 100;
		else if (b == c && b != a) val = 1000 + b * 100;
		else {
			int l = max(a, max(b, c));
			val = l * 100;
		}
		ans = max(ans, val);
	}

	cout << ans;
	return 0;
}