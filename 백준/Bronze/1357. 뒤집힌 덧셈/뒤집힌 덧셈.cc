#include<iostream>
#include<string>
using namespace std;

int rev(int s) {
	int ans = 0;
	while (s > 0) {
		ans = ans * 10 + s % 10;
		s /= 10;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int a, b;
	cin >> a >> b;
	cout << rev(rev(a) + rev(b));

	return 0;
}