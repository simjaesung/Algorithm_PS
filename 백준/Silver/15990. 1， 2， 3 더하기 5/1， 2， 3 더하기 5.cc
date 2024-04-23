#include <iostream>

using namespace std;
int D[100001][3] = { 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);
    
	int t,val,ans;
	cin >> t;

	D[1][0] = 1, D[2][1] = 1, 
		D[3][0] = 1, D[3][1] = 1, D[3][2] = 1;

	for (int i = 4; i <= 100000; i++) {
		D[i][0] = (D[i - 1][1] + D[i - 1][2]) % 1000000009;
		D[i][1] = (D[i - 2][0] + D[i - 2][2]) % 1000000009;
		D[i][2] = (D[i - 3][0] + D[i - 3][1]) % 1000000009;
	}

	while (t--) {
		cin >> val;
		ans = 0;
		for (int i = 0; i < 3; i++) {
			ans += D[val][i];
			ans %= 1000000009;
		}
		cout << ans << '\n';
	}
	return 0;
}