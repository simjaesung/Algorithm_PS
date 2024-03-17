#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, val, sum, s, e; 
long long ans = 0;
vector<int>v;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val; v.push_back(val);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			sum = v[i] + v[j];
			s = lower_bound(v.begin() + j + 1, v.end(), 0 - sum) - (v.begin() + j + 1);
			e = upper_bound(v.begin() + j + 1, v.end(), 0 - sum) - (v.begin() + j + 1);
			ans += e - s;
		}
	}
	cout << ans;

	return 0;
}