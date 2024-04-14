#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		while (n % i == 0) {
			n /= i;
			cout << i <<'\n';
		}
	}
	
	return 0;
}