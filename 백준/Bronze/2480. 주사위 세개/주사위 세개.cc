#include<iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (a == b && b == c) {
		cout << 10000 + a * 1000;
	}	
	else if ((a == b && a != c) || (a == c && a != b)){
		cout << 1000 + a * 100;
	}
	else if ((b == c && b != a)) {
		cout << 1000 + b * 100;
	}
	else {
		int tmp = a;
		if (b > tmp) tmp = b;
		if (c > tmp) tmp = c;

		cout << tmp * 100;
	}

	
	return 0;
}