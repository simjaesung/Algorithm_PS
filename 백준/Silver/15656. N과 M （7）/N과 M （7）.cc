#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int arr[10], memo[10];

void func(int k){
	if(k == m){
		for(int i = 0; i < m; i++){
			cout << memo[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = 0; i < n; i++){
		memo[k] = arr[i];
		func(k + 1);
	}
}


int main() {
	char input[100];
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	func(0);
	return 0;
}