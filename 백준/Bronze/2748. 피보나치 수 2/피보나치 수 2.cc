#include<iostream>
using namespace std;

long long F[100];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	F[0] = 0; F[1] = 1;
	for (int i = 2; i < 100; i++) F[i] = F[i - 1] + F[i - 2];
	
	cout << F[n];
	
	return 0;
}