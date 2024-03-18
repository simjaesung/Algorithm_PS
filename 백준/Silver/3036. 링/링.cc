#include<iostream>
using namespace std;
int arr[105];
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 1; i < n; i++) {
		int g = gcd(arr[0], arr[i]);
		cout << arr[0] / g << '/' << arr[i] / g << '\n';
	}
	return 0;
}