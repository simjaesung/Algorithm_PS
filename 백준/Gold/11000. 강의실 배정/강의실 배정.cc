#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<int, int>>time;
	for (int i = 0; i < n; i++) {
		int s, t; cin >> s >> t;
		time.push_back({ s,t });
	}
	
	sort(time.begin(), time.end());
	priority_queue<int, vector<int>, greater<>>q;

	for (int i = 0; i < n; i++) {
		int s, e;
		s = time[i].first; 
		e = time[i].second;
		if (!q.empty() && s >= q.top()) q.pop();
		q.push(e);
	}

	cout << q.size();
	return 0;
}
