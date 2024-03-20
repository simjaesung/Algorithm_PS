#include<iostream>
using namespace std;

int main()
{
	int l, a, b, c, d;
	cin >> l >> a >> b >> c >> d;

	int k = a / c;
	if (a % c != 0) k++;

	int s = b / d;
	if (b % d != 0) s++;

	int ans = l - max(k, s);
	cout << ans;

	return 0;
}