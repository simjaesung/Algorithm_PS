#include<iostream>
#include<algorithm>
#include<limits.h>
#include<cmath>
using namespace std;
int arr[4], c[4] = { 0,0,1,1 };
int a, b, ans = INT_MAX;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 4; i++) cin >> arr[i];
	
	do {
		a = 0; b = 0;
		for (int i = 0; i < 4; i++) {
			if (c[i] == 0) a += arr[i];
			else b += arr[i];
		}
		ans = min(ans, abs(a - b));
	} while (next_permutation(c, c + 4));

	cout << ans;
	
	return 0;
}