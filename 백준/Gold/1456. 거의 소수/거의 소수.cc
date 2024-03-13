#include<iostream>
using namespace std;
typedef long long ll;
int arr[10000005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	ll a, b; cin >> a >> b;

	for (ll i = 2; i * i <= b; i++) {
		if (!arr[i]) {
			for (ll j = i * 2; j * j <= b; j += i) arr[j] = 1;
		}
	}

	int ans = 0;
	for (ll i = 2; i * i <= b; i++) {
		if (!arr[i]) {
			ll val = i;
			while (val <= b / i) {
				if (val * i >= a) ans++;
				val *= i;
			}
		}
	}
	cout << ans;
	
	return 0;
}