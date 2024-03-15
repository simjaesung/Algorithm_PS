#include<iostream>
using namespace std;

int main()
{
	int t, m, s, val;
	cin >> t >> m >> s >> val;

	t += val / 3600; val %= 3600;
	m += val / 60;	val %= 60;
	s += val;

	m += s / 60; t += m / 60;
	t %= 24; m %= 60; s %= 60;

	cout << t << ' ' << m << ' ' << s;
	
	return 0;
}