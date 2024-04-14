#include<iostream>
using namespace std;

int ans[10];
int n, m;

void go(int k)
{
	if (k == m) {
		for (int i = 0; i < m; i++) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		ans[k] = i;
		go(k + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	go(0);
	return 0;
}