#include<iostream>
using namespace std;

int arr[1005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 1; i <= 1000; i++) arr[i] = arr[i - 1] + i;
	int t; cin >> t;
	while (t--) {
		int check = 0;
		int n; cin >> n;
		for (int i = 1; i <= 50; i++) {
			if (check) break;
			for (int j = 1; j <= 50; j++) {
				if (check) break;
				for (int k = 1; k <= 50; k++) {
					if (arr[i] + arr[j] + arr[k] == n) {
						check = 1;
						break;
					}
				}
			}
		}
		if (check) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	
	
	return 0;
}