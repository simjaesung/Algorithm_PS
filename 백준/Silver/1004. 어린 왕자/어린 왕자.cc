#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int x1, y1, x2, y2;
	while (n--) {
		cin >> x1 >> y1 >> x2 >> y2;
		int t; cin >> t;
		int ans = 0;
		while (t--) {
			int cx, cy, r;
			cin >> cx >> cy >> r;
			if (pow((cx - x1), 2) + pow((cy - y1), 2) < r * r 
				|| pow((cx - x2), 2) + pow((cy - y2), 2) < r * r) ans++;

			if (pow((cx - x1), 2) + pow((cy - y1), 2) < r * r
				&& pow((cx - x2), 2) + pow((cy - y2), 2) < r * r) ans--;
		}
		cout << ans << '\n';
	}
	return 0;
}