#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr[1001];

bool check[1001];

//호출 스택을 이용한
void dfs(int x) 
{
	check[x] = true;
	cout << x << ' ';
	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];
		if (!check[y]) dfs(y);
	}
}

void bfs(int x) 
{
	queue<int>q;
	fill(check, check + 1001, false);
	check[x] = true; q.push(x);

	while (!q.empty()) {
		int y = q.front(); q.pop();
		cout << y << ' ';
		for (int i = 0; i < arr[y].size(); i++) {
			int z = arr[y][i];
			if (!check[z]) {
				check[z] = true;
				q.push(z); 
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		//정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문
		sort(arr[i].begin(), arr[i].end());
	}
	dfs(v);
	cout << '\n';
	bfs(v);


	return 0;
}