#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>arr[3005];

int c[3005], ans[3005], v[3005];

//순환 출발점 찾는 함수
//2는 순환에 포함되어있다는 의미
int soon(int x, int px)
{
	if (c[x] == 1) return x;
	c[x] = 1;

	for (auto nx : arr[x]) {
		if (nx == px) continue;
		//전 좌표를 다시 가면 안됨
		int tmp = soon(nx, x);
		if (tmp == -1) return -1;
		if (tmp > 0) {
			c[x] = 2;
			if (tmp == x) return -1;
			else return tmp;
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	soon(1, 0);

	queue<int>q;

	for (int i = 1; i <= n; i++)
		if (c[i] == 2) q.push(i);

	while (!q.empty()) {
		int cx = q.front(); q.pop();
		v[cx] = 1;
		for (auto nx : arr[cx]) {
			if (v[nx] == 0 && c[nx] != 2) {
				ans[nx] = ans[cx] + 1;
				q.push(nx);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';

	return 0;
}