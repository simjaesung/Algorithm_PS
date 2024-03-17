#include<iostream>
using namespace std;
int ans, val;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	while (1) {
		cin >> val;
		if (val == -1) break;
		ans += val;
	}
	cout << ans;
	return 0;
}