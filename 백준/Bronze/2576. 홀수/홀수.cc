#include<iostream>
using namespace std;

int main()
{
	int arr[7];
	int sum = 0, ans = -1;

	for (int i = 0; i < 7; i++) {
		cin >> arr[i];
		if (arr[i] % 2 == 1) {
			if (ans != -1) ans = min(ans, arr[i]);
			else ans = arr[i];
			sum += arr[i];
		}
	}
	if (sum > 0)cout << sum << '\n' << ans;
	else cout << ans;



	return 0;
}