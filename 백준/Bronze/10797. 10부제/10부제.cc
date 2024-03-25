#include<iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	int ans = 0;

	if (a % 10 == n) ans++;
	if (b % 10 == n) ans++;
	if (c % 10 == n) ans++;
	if (d % 10 == n) ans++;
	if (e % 10 == n) ans++;

	cout << ans;

	
	return 0;
}