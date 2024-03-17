#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int a, b;
	cin >> a >> b;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (i + j == a) {
				if (i > j && i - j == b) {
					cout << i << ' ' << j;
					return 0;
				}
				else if (j >= i && j - i == b) {
					cout << j << ' ' << i;
					return 0;
				}
			}
		}
	}
	cout << -1;
	
	return 0;
}