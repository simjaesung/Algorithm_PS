#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int arr[100005], c[100005], v[100005];

int go(int x)
{
	if (v[x] == 1) {
		if (c[x] == 0) return x;
		else return -1;
	}
	v[x] = 1;

	int val = go(arr[x]);
	if (val == -1) {
		c[x] = 1;
		return -1;
	}
	if (val > 0) {
		c[x] = 2;
		if (x == val) return -1;
		else return val;
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--){
		fill(v, v + 100005, 0);
		fill(c, c + 100005, 0);

		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];

		for (int i = 1; i <= n; i++) if (v[i] == 0) go(i);
		
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (c[i] != 2) ans++;
		}
		cout << ans <<'\n';
	}
	
	return 0;
}