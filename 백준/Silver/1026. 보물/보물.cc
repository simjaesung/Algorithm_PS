#include<iostream>
#include<algorithm>
using namespace std;

int A[55], B[55];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];

	sort(A, A + n); sort(B, B + n);

	int ans = 0;

	for (int i = 0; i < n; i++) ans += A[i] * B[n - 1 - i];

	cout << ans;
	
	return 0;
}