#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; string s;
	cin >> n >> s;
	
	unsigned long long ans = 0;
	for (int i = 0; i < s.length(); i++) {
		unsigned long long val = s[i] - 'a' + 1;
		int k = i;
		while (k--) {
			val *= 31; 
			val %= 1234567891;
		}
		ans += val;
		ans %= 1234567891;
	}
	cout << ans;
	return 0;
}