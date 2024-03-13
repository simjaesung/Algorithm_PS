#include<iostream>
using namespace std;
int Hansoo(int n);

int main() {
	int N;
	cin >> N;
	cout << Hansoo(N);
	return 0;
}

int Hansoo(int n) {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (i < 100) {
			count += 1;
		}
		else{
			int a = i / 100;
			int b = (i - (100 * a)) / 10;
			int c = i - (100 * a) - (10 * b);
			if (b - c == a - b) {
				count += 1;
			}
		}
	}
	return count;
}