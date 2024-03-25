#include<iostream>
using namespace std;

int main()
{
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		int val; cin >> val;
		if (val < 40) sum += 40;
		else sum += val;
	}
	cout << sum / 5;
	
	return 0;
}