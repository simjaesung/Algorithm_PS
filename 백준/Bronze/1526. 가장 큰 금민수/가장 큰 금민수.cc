#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = n; i >= 0; i--) {
		int val = i;
		int check = 0;
		while (val > 0) {
			if (val % 10 != 7 && val % 10 != 4) check = 1;
			val /= 10;
		}

		if (!check) {
			cout << i;
			return 0;
		}
	}
	return 0;
}