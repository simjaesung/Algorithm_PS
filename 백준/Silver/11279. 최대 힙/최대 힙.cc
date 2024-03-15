#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<int, vector<int>>q;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	while (n--) {
		int val; cin >> val;

		if (val == 0) {
			if (q.empty()) cout << 0 << '\n';
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else q.push(val);
	}
	return 0;
}