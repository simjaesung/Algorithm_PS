#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int r, a, b;
	cin >> r >> a >> b;
	int ans = 0;
	while (a != b) {
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		ans++;
	}
	cout << ans;
	return 0;
}