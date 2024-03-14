#include<iostream>
#include<queue>
using namespace std;
int arr[200005] = { 0 };

void bfs(int x)
{
	queue<int>q;
	q.push(x);
	arr[x] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nx;
			if (i == 0) nx = now + 1;
			else if (i == 1) nx = now - 1;
			else nx = now * 2;

			if (nx > 200000 || nx < 0) continue;

			if (arr[nx] == 0) {
				arr[nx] = arr[now] + 1;
				q.push(nx);
			}
		}
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	bfs(n);
	cout << arr[k] - 1;

	return 0;
}