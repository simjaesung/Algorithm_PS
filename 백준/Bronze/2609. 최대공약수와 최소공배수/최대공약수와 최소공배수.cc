#include<iostream>

using namespace std;

int gcd(int a, int b)
{
	while(b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}


int main()
{
	int a, b, g, l;
	cin >> a >> b;

	if (b > a) {
		int swap = a;
		a = b;
		b = swap;
	}

	g = gcd(a, b);
	l = g * (a / g) * (b / g);

	cout << g << '\n' << l;
	
	return 0;
}