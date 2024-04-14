#include<iostream>
using namespace std;

int check[10], ans[10];
int n, m;

void go(int k)
{
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] <<' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (check[i]) continue;
		ans[k] = i; check[i] = 1;
		go(k + 1);
		check[i] = 0;
	}

}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	go(0);
	
	return 0;
}