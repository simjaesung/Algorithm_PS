#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while (n--) {
		int a, b, val, ans = 0; 
		cin >> a >> b;
		if (a == 0 || b == 0) ans++;

		for (int i = a; i <= b; i++) {
			val = i;
			while (val > 0) {
				if (val % 10 == 0) ans++;
				val /= 10;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}