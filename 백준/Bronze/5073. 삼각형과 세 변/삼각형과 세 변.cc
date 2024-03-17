#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)break;
		int tmp = max(a, max(b, c));
		int check = 0;
		if (tmp == a) {
			if (a >= b + c) check = 1;
		}
		else if (tmp == b) { 
			if (b >= a + c) check = 1;
		}
		else {
			if (c >= a + b) check = 1;
		}
		if (check) cout << "Invalid\n";
		else if (a == b && b == c) cout << "Equilateral\n";
		else if (a == b || b == c || a == c) cout << "Isosceles\n";
		else cout << "Scalene\n";
	}
	
	
	return 0;
}