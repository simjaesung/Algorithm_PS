#include<iostream>
using namespace std;

int n, s,ans = 0;
int arr[25], check[25];

void go(int select, int index, int m, int sum)
{
	if (select == m) {
		if (sum == s) ans++;
		return;
	}
	if (index > n -1 ) return;
	go(select + 1, index + 1, m, sum + arr[index]);
	go(select, index + 1, m, sum);
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int k = 1; k <= n; k++) go(0, 0, k, 0);
	cout << ans;
	return 0;
}