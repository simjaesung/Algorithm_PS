#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int A[20001];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;

	while (t--) {
		int a, b; 
		cin >> a >> b;
		
		for (int i = 0; i < a; i++) cin >> A[i];

		sort(A, A + a);

		int cnt = 0; int ans = 0;

		for (int i = 0; i < b; i++) {
			int val; cin >> val;
			ans += a - (upper_bound(A, A + a, val) - A);
			
		}

		cout << ans << '\n';
	}


	return 0;
}