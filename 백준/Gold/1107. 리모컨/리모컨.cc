#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(nullptr); cout.tie(nullptr);

	char num[10] = { '0','1','2','3','4','5','6','7','8','9' };
	
	int channel, ans_len = 0;
	int n, k, ans = 500000;
	cin >> channel;	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k; 
		num[k] = 'x';
	}

	for (int i = 0; i <= 1000000; i++) {
		int check = 0;
		string s = to_string(i);
		for (int k = 0; k < s.length(); k++) {
			if (num[s[k] - '0'] != s[k]) {
				check = 1;
				break;
			}
		}
		if (!check) {
			if (ans > abs(channel - i)) {
				ans = abs(channel - i);
				ans_len = s.length();
			}
		}
	}
	ans = min(abs(channel - 100), ans_len + ans);

	cout << ans;

	return 0;
} 