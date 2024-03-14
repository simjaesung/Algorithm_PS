#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arrp[55], arrm[55];

bool compare(int a, int b) {
	return a > b;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int>p; vector<int>m;
	for (int i = 0; i < n; i++) {
		int val; cin >> val;
		if (val > 0) p.push_back(val);
		else m.push_back(val);
	}
	sort(p.begin(), p.end(), compare);
	sort(m.begin(), m.end());

	int ans = 0;

	for (int i = 0; i < p.size(); i++) {
		if (i != p.size() - 1) {
			if (p[i] != 1 && p[i + 1] != 1) {
				ans += p[i] * p[i + 1];
				i++;
			}
			else ans += p[i];
		}
		else ans += p[i];
	}

	for (int i = 0; i < m.size(); i++) {
		if (i != m.size() - 1) {
			ans += m[i] * m[i + 1];
			i++;
		}
		else ans += m[i];
	}

	cout << ans;
	return 0;
}