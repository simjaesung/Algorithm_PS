#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int m = a + b + c + d;

	cout << m / 60 << '\n' << m % 60;
	
	return 0;
}