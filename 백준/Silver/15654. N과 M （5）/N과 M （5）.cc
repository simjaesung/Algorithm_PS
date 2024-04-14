#include<iostream>
#include<algorithm>
using namespace std;

int ans[10], arr[10], check[10];
int n, m;

void go(int k)
{
	if (k == m) {
		for (int i = 0; i < m; i++) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		check[i] = 1; ans[k] = arr[i];
		go(k + 1);
		check[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	go(0);
	return 0;
}