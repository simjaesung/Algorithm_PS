#include<iostream>
#include<vector>
#include<string>
using namespace std;
int arr[2000005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	vector<int>s;
	for (int i = 2; i <= 2000005; i++) {
		if (arr[i]) continue;
		s.push_back(i);
		for (int j = i; j <= 2000005; j += i) arr[j] = 1;
	}

	int n; cin >> n;
	
	for (auto x : s) {
		if (x < n) continue;
		string k;
		int ans = x;
		while (x > 0) {
			int val = x % 10;
			k += char(val + 48);
			x /= 10;
		}
		int check = 1;
		for (int i = 0; i < k.length() / 2; i++) {
			if (k[i] != k[k.length() - 1 - i]) check = 0;
		}
		if (check) {
			cout << ans;
			return 0;
		}
	}
	return 0;
}