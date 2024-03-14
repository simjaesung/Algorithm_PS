#include<iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string ans;

	if (n == 0) ans = "0";
	else {
		while (n != 0) {
			if (n % -2 == 0) {
				ans += "0";
				n /= -2;
			}
			else {
				ans += "1";
				n = (n - 1) / -2;
			}
		}
	} 
	reverse(ans.begin(), ans.end());
	cout << ans;
	
	return 0;
}