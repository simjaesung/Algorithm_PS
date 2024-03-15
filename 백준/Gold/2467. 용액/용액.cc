#include<iostream>
#include<vector>
#include<limits.h>
#include<cmath>
using namespace std;
vector<int>v;
int n, val, s, e, m, tmp = INT_MAX;
int ans1, ans2;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val; 
		v.push_back(val);
	}

	for (int i = 0; i < n; i++) {
		s = i + 1; e = n - 1;
		while (s <= e) {
			m = (s + e) / 2;
			if (abs(v[i] + v[m]) < tmp) {
				tmp = abs(v[i] + v[m]);
				ans1 = v[i]; ans2 = v[m];
			}
			if (v[i] + v[m] < 0) s = m + 1;
			else e = m - 1;
		}
	}
	cout << ans1 << ' ' << ans2;
	
	return 0;
}