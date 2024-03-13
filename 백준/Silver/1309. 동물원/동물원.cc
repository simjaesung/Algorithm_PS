#include<iostream>
using namespace std;

int D[100001] = { 1 };

int main()
{
	int n; 
	cin >> n;

	D[1] = 3;
	for (int i = 2; i <= n; i++) {
		D[i] = 2 * D[i - 1] + D[i - 2];
		D[i] %= 9901;
	}
		
	cout << D[n];
	return 0;
}