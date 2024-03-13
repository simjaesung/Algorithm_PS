#include<iostream>
#include<deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(nullptr);
	int n, m, ans = 0;
	cin >> n >> m;
	deque<int>d;

	for (int i = 1; i <= n; i++) d.push_back(i);

	while(m--) {
		int val, idx;
		cin >> val;

		for (int i = 0; i < d.size(); i++) if (d[i] == val) idx = i;

		while (d.front() != val) {
			if (idx > d.size() - idx) {
				d.push_front(d.back());
				d.pop_back();
			}
			else {
				d.push_back(d.front());
				d.pop_front();
			} 
			ans++;
		}
		d.pop_front();
	}
	cout << ans;

	
	return 0;
}