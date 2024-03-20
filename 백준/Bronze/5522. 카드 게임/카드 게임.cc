#include<iostream>
using namespace std;
int main()
{
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		int val; cin >> val;
		ans += val;
	}
	cout << ans;
	return 0;
}