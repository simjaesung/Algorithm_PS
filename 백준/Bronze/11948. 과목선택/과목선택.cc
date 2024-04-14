#include<iostream>
using namespace std;
int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	int k = min(min(a, b), min(c, d));
	int s = max(e, f);

	cout << a + b + c + d - k + s;
	return 0;
}