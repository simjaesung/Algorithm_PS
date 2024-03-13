#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,arr[26];
string ans;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	while (n--) {
		string s; cin >> s;
		arr[s[0]-'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 5) ans += char(i + 'a');
	}

	cout << ans;
	if (ans.length() == 0) cout << "PREDAJA";
	return 0;
}