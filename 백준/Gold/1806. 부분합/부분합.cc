#include<iostream>
using namespace std;

int arr[100005];
int n, s, tmp, st, en, ans = 100005;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];

	while (st <= n && en <= n) {
		if (tmp < s) tmp += arr[en++];
		else {
			ans = min(ans, en - st);
			tmp -= arr[st++];
		}
	}
	if (ans == 100005) cout << 0;
	else cout << ans;
	return 0;
}