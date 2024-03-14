#include<iostream>
#include<algorithm>
using namespace std;

char pw[15];
int check[15];
char mom[5] = { 'a','e','i','o','u' };

void go(int index, int select, int n,int m) 
{
	if (select == n) {
		int mo = 0, ja = 0;
		for (int i = 0; i < n; i++) {
			int c = 0;
			for (int j = 0; j < 5; j++) 
				if (pw[check[i]] == mom[j]) c = 1;
			
			if (c) mo++;
			else ja++;
		}
		if (mo > 0 && ja > 1 ) {
			for (int i = 0; i < n; i++) cout << pw[check[i]];
			cout << '\n';
		}
		return;
	}
	if (index > m) return;

	check[select] = index;
	go(index + 1, select + 1, n, m);
	check[select] = 0;
	go(index + 1, select, n, m);
}

int main()
{
	int l, c;
	cin >> l >> c;
	for (int i = 1; i <= c; i++) cin >> pw[i];
	sort(pw, pw + c + 1);
	go(1, 0, l, c);
	return 0;
}