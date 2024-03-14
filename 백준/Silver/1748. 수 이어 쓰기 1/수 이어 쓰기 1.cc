#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int k = 9, i = 1;
	int ans = 0;

	while (n > k)
	{
		n -= k;
		ans += k * i++;
		k *= 10;
	}
	ans += n * i;

	cout << ans;
	return 0;
}