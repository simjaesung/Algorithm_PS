#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;

	while (t--) {
		queue<pair<int, int>>q;
		vector<int>v;
		int n, f, idx = 0;
		cin >> n >> f;
		for (int i = 0; i < n; i++) {
			int val; cin >> val; //우선순위
			q.push(make_pair(i, val));
			v.push_back(val);
		}
		sort(v.begin(), v.end(), compare);

		int ans = 0;

		while (!q.empty()) {
			if (q.front().second != v[idx]) {
				q.push(q.front());
				q.pop();
			}
			else {
				idx++; ans++; 
				if (q.front().first == f) break;
				q.pop();
			}
		}
		cout << ans <<'\n';
	}
	
	return 0;
}