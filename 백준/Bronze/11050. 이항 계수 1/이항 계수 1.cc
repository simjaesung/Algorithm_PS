#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;
	int ans = 1;
	int r = 1;
	for (int i = n; i > n - m; i--) {
		ans *= i;
		ans /= r;
		r++;
	}
	cout << ans << '\n';
	

	return 0;
}