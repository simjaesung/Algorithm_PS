#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int arr[100001], c[100001];


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	fill(c, c + 100001, -1);

	deque<int>dq;
	dq.push_back(n); c[n] = 0;

	while (!dq.empty()) {
		int cx = dq.front();
		dq.pop_front();

		for (int nx : {cx * 2, cx - 1, cx + 1}) {
			if (nx > 100001 || nx < 0) continue;
			if (nx == cx * 2) {
				if (c[nx] == -1) {
					c[nx] = c[cx];
					dq.push_front(nx);
				}
			}
			else {
				if (c[nx] == -1) {
					c[nx] = c[cx] + 1;
					dq.push_back(nx);
				}
			}
		}
	}
	cout << c[m];


	return 0;
}