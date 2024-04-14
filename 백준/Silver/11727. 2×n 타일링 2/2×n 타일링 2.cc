#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int>T(n+1);
	T[1] = 1, T[2] = 3;

	for (int i = 3; i <= n; i++) 
		T[i] = (T[i - 1] + 2* T[i - 2]) % 10007;
		
	cout << T[n];

	return 0;
}