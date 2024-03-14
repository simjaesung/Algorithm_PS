#include<iostream>
using namespace std;
int n, s, e, arr[100005], c[100005];
long long ans;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	c[arr[0]] = 1;
	for (int i = 0; i < n; i++) {
		while (e < n - 1 && !c[arr[e + 1]]) {
			e++;
			c[arr[e]] = 1;
		}
		ans += e - i + 1;
		c[arr[i]] = 0;
	}

	cout << ans;

	return 0;
}