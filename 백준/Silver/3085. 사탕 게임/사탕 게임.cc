#include<iostream>
#include<algorithm>
using namespace std;
char c[51][51];

int find_longest(int size) {
	int result = 0, val;
	//가로
	for (int i = 1; i <= size; i++) {
		val = 1;
		for (int l = 2; l <= size; l++) {
			if (c[i][l] == c[i][l - 1])	val++;
			else val = 1;
			result = max(result, val);
		}
		
	}
	//세로
	for (int j = 1; j <= size; j++) {
		val = 1;
		for (int k = 2; k <= size; k++) {
			if (c[k][j] == c[k - 1][j]) val++;
			else val = 1;
			result = max(result, val);
		}
	}
	return result;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int n, ans = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			swap(c[i][j], c[i][j + 1]);
			ans = max(ans, find_longest(n));
			swap(c[i][j], c[i][j + 1]);

			if (i < n) {
				swap(c[i][j], c[i + 1][j]);
				ans = max(ans, find_longest(n));
				swap(c[i][j], c[i + 1][j]);
			}
		}
	}
	cout << ans;

	return 0;
}