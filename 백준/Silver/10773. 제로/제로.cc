#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0); cin.tie(nullptr);
	int n; cin >> n;
	stack<ll>s;
	while (n--) {
		ll val; cin >> val;
		if (val == 0) {
			if (!s.empty()) s.pop();
		}
		else {
			s.push(val);
		}
	}
	ll ans = 0;
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	cout << ans;
	
	return 0;
}