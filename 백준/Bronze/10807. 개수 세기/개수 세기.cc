#include<iostream>
using namespace std;

int main()
{
	int arr[101];
	int n, val, ans = 0; 
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cin >> val;
	
	for (int i = 1; i <= n; i++) if (arr[i] == val) ans++;
	cout << ans;

	return 0;
}