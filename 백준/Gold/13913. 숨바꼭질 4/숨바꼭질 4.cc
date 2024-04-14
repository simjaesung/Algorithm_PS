#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

int arr[100001], c[100001],cidx[100001][3];
//cidx는 어느 경로로 nx에 접근했는지 저장
//0: x-1 / 1 : x + 1 / 2 : x * 2

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < 100001; i++)
		fill(cidx[i], cidx[i] + 3, -1);

	queue<int>q;
	q.push(n);
	c[n] = 1;
	while (!q.empty()) {
		int cx = q.front(); q.pop();
		if (cx == m)break;
		for (int nx : {cx - 1, cx + 1, cx * 2}) {
			if (nx < 0 || nx > 100000) continue;

			if (c[nx] == 0) {
				if (nx == cx - 1) cidx[nx][0] = cx;
				else if (nx == cx + 1) cidx[nx][1] = cx;
				else cidx[nx][2] = cx;

				c[nx] = c[cx] + 1;
				q.push(nx);
			}

		}
	}
	
	int ans = c[m];
	cout << ans - 1 << '\n';

	stack<int>s;
	int k = m;
	while (1) {
		int check = 1;
		s.push(k);
		for (int i = 0; i < 3; i++) {
			if (cidx[k][i] != -1) {
				k = cidx[k][i];
				check = 0;
				break;
			}
		}
		if (check) break;
	}

	while (!s.empty()) {
		cout << s.top() <<' ';
		s.pop();
	}
	

	return 0;
}
