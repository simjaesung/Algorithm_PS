#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
typedef long long ll;

ll n, c, val, m, s, e, g, p, ans;
vector<ll>v;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> val; v.push_back(val);
	}

	sort(v.begin(), v.end());
	s = 1; 
	e = v[n - 1] - v[0];

	while (s <= e) {
		m = (s + e) / 2; //공유기를 설치할 간격
		g = 1; //설치한 공유기 개수
		p = v[0]; //
		for (int i = 1; i < n; i++) {
			if ((v[i] - p) >= m) {
				g++; 
				p = v[i];
			}
		}

		if (g >= c) {
			s = m + 1;
			ans = m;
		}
		else e = m - 1;
	}
	cout << ans;
	return 0;
}