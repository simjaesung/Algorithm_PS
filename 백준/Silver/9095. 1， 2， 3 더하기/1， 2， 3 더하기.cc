#include<iostream>
using namespace std;

int d[15];
int main()
{
	d[1] = 1; d[2] = 2; d[3] = 4;
	for (int i = 4; i <= 11; i++) {
		d[i] = d[i - 3] + d[i - 2] + d[i - 1];
	}
	int t; cin >> t;
	while (t--) {
		int val; cin >> val;
		cout << d[val] << '\n';
	}
	
	return 0;
}