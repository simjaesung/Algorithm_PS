#include<iostream>
using namespace std;

int pic[100][100];

bool check(int x, int y, int n)
{
	int val = pic[x][y];
	for (int i = x; i < x+n; i++) {
		for (int j = y; j < y+n; j++) {
			if (val != pic[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void cut(int a, int b, int n)
{
	if (check(a, b, n)) {
		cout << pic[a][b];
		return;
	}
	cout << '(';
	int l = n / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cut(a + l * i, b + l * j, l);
		}
	}
	cout << ')';
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++)
			pic[i][j] = s[j] - '0';
	}

	
	cut(0, 0, n);
	
	return 0;
}