#include<iostream>
#include<algorithm>
using namespace std;

int arr[105];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) arr[i] = i;
	while (m--) {
		int a, b;
		cin >> a >> b;
		while (a <= b) {
			swap(arr[a], arr[b]);
			a++; b--;
		}
	}
	for (int i = 1; i <= n; i++) cout << arr[i] << ' ';

	return 0;
}