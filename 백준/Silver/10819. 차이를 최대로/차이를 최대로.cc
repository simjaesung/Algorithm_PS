#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(nullptr);
	int n; cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(),v.end());
	int ans = 0;
	do {
		int val = 0;
		for (int i = 0; i < n - 1; i++) val += abs(v[i] - v[i + 1]);

		ans = max(ans, val);
	} while (next_permutation(v.begin(), v.end()));

	cout << ans;
	return 0;
}