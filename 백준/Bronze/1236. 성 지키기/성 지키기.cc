#include<iostream>
using namespace std;
int arr[55];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, ans1 = 0,ans2 = 0;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int check = 0;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'X') {
				check = 1;
				arr[j]++;
			}
		}
		if (!check) ans1++;
	}

	for (int i = 0; i < m; i++) {
		if (arr[i] == 0) ans2++;
	}

	cout << max(ans1, ans2);
	return 0;
}