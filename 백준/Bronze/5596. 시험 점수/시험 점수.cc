#include<iostream>
using namespace std;

int main()
{
	int mk = 0, ms = 0;

	for (int i = 0; i < 4; i++) {
		int a; cin >> a;
		mk += a;
	}

	for (int i = 0; i < 4; i++) {
		int a; cin >> a;
		ms += a;
	}

	cout << max(mk, ms);
	return 0;
}