#include<iostream>
using namespace std;
char s[4000][7000];

void draw(int x, int y, int n) {
	if (n == 3) {
		s[x][y] = '*';
		s[x + 1][y - 1] = '*';
		s[x + 1][y + 1] = '*';
		s[x + 2][y - 2] = '*';
		s[x + 2][y - 1] = '*';
		s[x + 2][y] = '*';
		s[x + 2][y + 1] = '*';
		s[x + 2][y + 2] = '*';
	}
	else {
		draw(x, y, n / 2);
		draw(x + n / 2, y - n / 2, n / 2);
		draw(x + n / 2, y + n / 2, n / 2);
	}

}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 4000; i++)
		fill(s[i], s[i] + 7000, ' ');

	int n; cin >> n;

	draw(0, n - 1, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			cout << s[i][j];
		}
		cout << '\n';
	}
	
	
	return 0;
}