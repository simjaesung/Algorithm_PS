#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int inT = 0, ans = 0;
	while (1) {
		int a, b;
		cin >> a >> b;
		inT += b; inT -= a;
		ans = max(ans, inT);

		if (b == 0) break;
	}
	cout << ans;
	
	return 0;
}