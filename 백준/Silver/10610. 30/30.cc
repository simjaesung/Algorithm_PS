#include<iostream>
#include<algorithm>
using namespace std;

bool compare(char a, char b) {
	return a > b;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string n; cin >> n;

	int tmp = 0;
	for (int i = 0; i < n.length(); i++) tmp += n[i] - '0';

	if (tmp % 3 == 0) {
		sort(n.begin(),n.end(),compare);
		if (n[n.length() - 1] != '0') {
			cout << -1; return 0;
		}
		cout << n;
	}
	else cout << -1;
	
	return 0;
}