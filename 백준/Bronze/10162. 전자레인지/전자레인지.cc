#include<iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	if (n % 10 != 0) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			cout << n / 300 << ' ';
			n %= 300;
		}
		else if (i == 1) {
			cout << n / 60 << ' ';
			n %= 60;
		}
		else cout << n / 10;
	}
	
	return 0;
}