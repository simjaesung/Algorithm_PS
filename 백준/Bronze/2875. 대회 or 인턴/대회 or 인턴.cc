#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;

	int ans = 0;
	for (int i = 0; i <= k; i++) {
		int g = n, b = m;
		g -= i; 
		b -= k - i;
		ans = max(ans, min(g / 2, b));
	}

	cout << ans;
	return 0;
}