#include<iostream>
using namespace std;

int main()
{
	int  a, b, n;
	cin >> a >> b >> n;
	a %= b;
	int ans;
	while(n--) {
		a *= 10;
		ans = a / b;
		a %= b;
	}
	cout << ans;
	return 0;
}