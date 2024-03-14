#include <iostream>

using namespace std;

int prime(int val) 
{
	if (val < 2) return 0;

	for (int i = 2; i <= val/2; i++) {
		if (val % i == 0) return 0;
	}
	return 1;
}

int main()
{
	int n, val, answer = 0;
	cin >> n;

	while (n--) {
		cin >> val;
		if (prime(val)) answer++;
	}

	cout << answer;
	
	return 0;
}