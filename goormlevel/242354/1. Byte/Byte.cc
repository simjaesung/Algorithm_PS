#include <iostream>
using namespace std;
int ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	for(auto x : s) ans++;
	cout << ans;
	return 0;
}