#include<iostream>
using namespace std;

int arr[150][150], ans[2];

bool check(int a, int b,int n) {
	int val = arr[a][b];
	for (int i = a; i < a+n; i++) {
		for (int j =b; j < b+n; j++) {
			if (val != arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}


void cut(int a, int b, int n)
{
	if (check(a, b, n)) {
		ans[arr[a][b]]++;
		return;
	}

	int l = n / 2;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			cut(a + i * l, b + j * l, l);
	}

}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cut(0, 0, n);
	for (int k = 0; k < 2; k++) cout << ans[k] << '\n';

	return 0;
}