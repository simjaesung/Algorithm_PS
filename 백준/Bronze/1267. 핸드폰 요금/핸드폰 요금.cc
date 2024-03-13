#include<iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int call[20];
	int y = 0, m = 0;
	 
	for (int i = 0; i < n; i++) {
		cin >> call[i];
		y += call[i] / 30 + 1;
		m += call[i] / 60 + 1;
	}

	y *= 10; m *= 15;

	if (y > m) cout << "M " << m;
	else if (m > y) cout << "Y " << y;
	else cout << "Y M "  << y;
	
	return 0;
}