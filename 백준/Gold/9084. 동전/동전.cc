#include<iostream>
#include<algorithm>
using namespace std;
int arr[25], d[10005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		fill(d, d + 10005, 0);
		int n,m; cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];

		cin >> m;

		for (int i = 0; i < n; i++) {
			d[arr[i]] += 1;
			for (int j = arr[i] + 1; j <= m; j++) {
				d[j] += d[j - arr[i]];
			}
		}
		
		cout <<d[m]<< '\n';
	}
	return 0;
}