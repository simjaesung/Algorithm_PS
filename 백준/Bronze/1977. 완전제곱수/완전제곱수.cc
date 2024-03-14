#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int a, b; cin >> a >> b;
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i * i <= 10000; i++) {
		if (i * i >= a && i * i <= b) {
			if (ans1 == 0) ans1 = i * i;
			ans2 += i * i;
		}
	}
	
	if (ans1 == 0) cout << -1;
	else cout << ans2 << '\n' << ans1;
	return 0;
}