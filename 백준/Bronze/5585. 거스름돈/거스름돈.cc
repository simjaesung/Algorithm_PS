#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; n = 1000 - n;

	int j[] = { 500,100,50,10,5,1 };

	int ans = 0;
	for (int i = 0; i < 6; i++) {
		while (n >= j[i]) {
			n -= j[i];
			ans++;
		}
	}
	cout << ans;
	
	return 0;
}