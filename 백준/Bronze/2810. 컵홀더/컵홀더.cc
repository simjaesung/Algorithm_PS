#include<iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	string s; cin >> s;

	int cntL = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') cntL++;
	}

	cout << min(n, n + 1 - cntL / 2);
	
	return 0;
}