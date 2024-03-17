#include<iostream>
using namespace std;
int arr[5];
int main()
{
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < 5; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int sum = a + b + c + d;
		arr[i] = sum;
		if (sum > ans2) {
			ans1 = i + 1; ans2 = sum;
		}
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}