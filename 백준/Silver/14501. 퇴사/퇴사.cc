#include<iostream>
using namespace std;

int T[16], P[16];
int c[15];
int ans = 0;
void go(int idx, int select, int n)
{
	if (idx == n) {
		int tmp = 0;
		for (int i = 0; i < select; i++) tmp += P[c[i]];
		ans = max(ans, tmp);
		return;
	}
	if (idx > n) return;

	c[select] = idx;
	go(idx + T[idx], select + 1, n);
	c[select] =0;
	go(idx + 1, select, n);
}


int main()
{
	int n; cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> T[i];
		cin >> P[i];
	}

	go(1, 0, n + 1);
	cout << ans;
	return 0;
}