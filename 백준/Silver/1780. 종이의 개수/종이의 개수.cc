#include<iostream>
using namespace std;

int arr[2200][2200], ans[3];

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
		ans[arr[a][b] + 1]++;
		return;
	}

	int l = n / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cut(a + i*l, b + j*l, l);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	cut(1, 1, n);
	
	for (int k = 0; k < 3; k++)
		cout << ans[k] << '\n';
	return 0;
}