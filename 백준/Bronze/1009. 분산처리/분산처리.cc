#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		
		vector<int>v;

		int val = 1;
		for (int i = 0; i < 4; i++) {
			val *= a;	val %= 10;
			v.push_back(val);
		}
		b = (b + 3) % 4;
		int ans = v[b];
		if (ans == 0) cout << 10 << '\n';
		else cout << ans << '\n';
	}
	
	return 0;
}