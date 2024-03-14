#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	long long s; cin >> s;
	long long val = 1;
	while (1) {
		if ((val * (val + 1) / 2) > s) break;
		val++;
	}
	cout << val - 1;
	
	return 0;
}