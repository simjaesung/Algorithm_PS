#include<iostream>
using namespace std;

int main()
{
	int sum; cin >> sum;
	int n = 9;
	while (n--) {
		int val; cin >> val;
		sum -= val;
	}
	cout << sum;
	
	return 0;
}