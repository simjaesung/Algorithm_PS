#include<iostream>
using namespace std;

int arr[100005], d[100005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n,t; cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) d[i] = d[i - 1] + arr[i];

	while (t--) {
		int i, j;
		cin >> i >> j;
		cout << d[j] - d[i - 1] << '\n';
	}
	
	return 0;
}