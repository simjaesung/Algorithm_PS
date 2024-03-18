#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int cnt = 1;
	while (1) {
		int l, p, v;
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) break;

		int ans = 0;

		ans += l * (v / p);

		if (l > v % p) ans += v % p;
		else ans += l;

		cout << "Case " << cnt++ << ": " << ans <<'\n';
	}
	
	return 0;
}