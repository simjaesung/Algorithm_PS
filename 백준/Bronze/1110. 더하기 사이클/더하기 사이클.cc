#include <iostream>
using namespace std;

int main() {
	int n;
	int count = 0;	
	cin >> n;
	int copy = n;
	while (true) {
		int a = copy / 10;
		int b = copy % 10;
		int c = (a + b) % 10;
		copy = 10 * b + c;
		count += 1;
		if (copy == n) { break; }
	}
	cout << count;
	return 0;
}