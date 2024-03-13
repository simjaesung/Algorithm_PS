#include<iostream>
using namespace std;
int arr[1005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int idx = 0; int val = 1;

	while (idx < 1000) {
		int tmp = val;
		while (val--) {
			arr[idx] = tmp;
			idx++;
			if (idx == 1000) break;
		}
		val = tmp + 1;
	}

	int a, b; cin >> a >> b;
	int ans = 0;
	
	for (int i = a - 1; i < b; i++) ans += arr[i];
	cout << ans;
	return 0;
}