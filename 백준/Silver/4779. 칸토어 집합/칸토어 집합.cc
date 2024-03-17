#include<iostream>
#include <cmath>
using namespace std;
char k[550000];

void kanto(int n,int idx) 
{
	if (n == 0) return;
	for (int i = idx + n / 3; i < idx + (n / 3) * 2; i++) {
		k[i] = ' ';
	}
	kanto(n / 3, idx); 
	kanto(n / 3, idx + n / 3 * 2);
}


int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	while (1) {
		fill(k, k + 550000, '-');
		int n; cin >> n;
		if (cin.eof()) break;

		kanto(pow(3, n), 0);
		for (int i = 0; i < pow(3, n); i++)
			cout << k[i] ;

		cout << '\n';
	}
	
	
	return 0;
}