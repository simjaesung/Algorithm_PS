#include<iostream>
#include<algorithm>
using namespace std;
int arr[10];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < 10; i++) cin >> arr[i];
		sort(arr, arr + 10);
		cout << arr[7] << '\n';
	}
	
	return 0;
}