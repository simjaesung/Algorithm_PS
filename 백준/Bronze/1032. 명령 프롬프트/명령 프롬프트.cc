#include<iostream>
using namespace std;

char arr[55][55];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];


	for (int i = 0; i < 55; i++) {
		int check = 0; char tmp = arr[0][i];
		if (tmp == NULL) break;

		for (int j = 1; j < n; j++) {
			if (arr[j][i] != tmp) {
				check = 1; break;
			}
		}

		if (check) cout << '?';
		else cout << tmp;
	}
	

	return 0;
}