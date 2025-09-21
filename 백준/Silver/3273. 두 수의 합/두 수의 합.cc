#include <iostream>
using namespace std;

int check[2000005];
int ans;
int main() {
	int n,x;
	cin >> n;
	int arr[n];

	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		check[arr[i]]++;
	}
	
	cin >> x;

	for(int i = 0; i < n; i++) {
		if(x-arr[i] == arr[i]) continue;
		if(x-arr[i] <= 0) continue;
		if(check[x-arr[i]]) {
			ans++;
		}
	}
	cout << ans / 2;
	return 0;
}