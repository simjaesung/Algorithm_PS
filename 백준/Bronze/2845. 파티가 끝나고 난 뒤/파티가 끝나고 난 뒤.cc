#include<iostream>
using namespace std;

int main()
{
	int n, s; 
	cin >> n >> s;

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	int ns = n * s;
	cout << a - ns << ' ' << b - ns << ' ' << c - ns << ' ' << d - ns << ' ' << e - ns;
	
	return 0;
}