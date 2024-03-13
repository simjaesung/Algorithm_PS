#include<iostream>
#include<math.h>
using namespace std;

char arr[55][55];

int n, m;
int val;
int ans = 32;
int toggle = 1; //w

bool inrange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

void check(int x, int y) {
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if (toggle == 1) {
				if (arr[i][j] != 'W') val++;
			}
			else {
				if (arr[i][j] != 'B') val++;
			}
			toggle = -toggle;
		}

		toggle = -toggle;
	}
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) arr[i][j] = s[j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (inrange(i + 7, j + 7)) {
				toggle = 1; val = 0;
				check(i, j);
				ans = min(ans, val);

				toggle = -1; val = 0;
				check(i, j);
				ans = min(ans, val);
			}
		}
	}

	cout << ans;


	return 0;
}