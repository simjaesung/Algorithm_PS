#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(nullptr);
	int arr[11][11];
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	vector<int>v(n);
	for (int i = 0; i < n; i++) v[i] = i + 1;

	int ans = 4000001;
	do {
		int check = 1, val = 0;
		for (int i = 0; i < n; i++) {
			int tmp;
			if (i == n - 1) tmp = arr[v[n - 1]][v[0]];
			else tmp = arr[v[i]][v[i + 1]];

			if (tmp == 0) {
				check = 0; 
				break;
			}
			else val += tmp;
		}
		if (check) ans = min(ans, val);

	} while (next_permutation(v.begin() +1, v.end()));
	
	cout << ans;

	return 0;
}