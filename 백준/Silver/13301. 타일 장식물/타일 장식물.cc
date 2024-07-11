#include <iostream>
using namespace std;
long long n,arr[100];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	arr[0] = 1, arr[1] = 1;
	for(int i = 2; i<=80; i++){
		arr[i] = arr[i-2] + arr[i-1];
	}
	cout << arr[n-1] * 4 + arr[n-2] * 2;
	return 0;
}