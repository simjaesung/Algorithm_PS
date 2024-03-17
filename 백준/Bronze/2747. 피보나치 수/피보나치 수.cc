#include<iostream>
using namespace std;
long long F[50];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	F[1] = 1;
	for (int i = 2; i <= 45; i++) F[i] = F[i - 2] + F[i - 1];

	int n; cin >> n;

	cout << F[n];
	
	return 0;
}