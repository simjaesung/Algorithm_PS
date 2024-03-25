#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	if (a < 2) {
		cout << "Before";
		return 0;
	}

	if (a == 2 && b < 18) {
		cout << "Before";
		return 0;
	}

	if (a == 2 && b == 18) {
		cout << "Special";
		return 0;
	}
	cout << "After";
	
	return 0;
}