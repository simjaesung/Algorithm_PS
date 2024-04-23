#include<iostream>
using namespace std;

int cnt;

int isPalindrome(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] == s[s.length() - 1 - i]) cnt++;
        else return 0;
    }
    return 1;
}



int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cnt = 1;
        string s; cin >> s;
        int ans1 = isPalindrome(s);
        cout << ans1 << ' ' << cnt << '\n';
    }

	return 0;
}