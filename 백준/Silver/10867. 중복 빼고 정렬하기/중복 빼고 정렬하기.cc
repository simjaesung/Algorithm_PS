#include<iostream>
#include<algorithm>
using namespace std;
int arr[100005], c[2005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		c[arr[i] + 1000]++;
	}

	for (int i = 0; i < 2005; i++) 
		if (c[i] != 0) cout << i - 1000 << ' ';
	
	return 0;
}