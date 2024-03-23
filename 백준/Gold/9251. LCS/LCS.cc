#include<iostream>
using namespace std;
int d[1005][1005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string a, b;
	cin >> a >> b;

	int lena = a.length();
	int lenb = b.length();

	for (int i = 1; i <= lena; i++) {
		for (int j = 1; j <= lenb; j++) {
			if (a[i - 1] == b[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
			else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}

	cout << d[lena][lenb];

	return 0;
}