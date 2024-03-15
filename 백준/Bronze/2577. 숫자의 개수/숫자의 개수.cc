#include<iostream>
using namespace std;
int main()
{
	int a, b, c,mult;
	int ans[10] = { 0 };
	cin >> a >> b >> c;
	mult = a * b * c;

	while (mult > 0) {
		ans[mult % 10]++;
		mult /= 10;
	}

	for (auto& x : ans) cout << x << '\n';
	
	return 0;
}