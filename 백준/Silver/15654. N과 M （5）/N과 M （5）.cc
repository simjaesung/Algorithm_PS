#include <iostream>
#include <algorithm>
using namespace std;

int n,m,arr[10],check[10],memo[10];

void func(int k){
	if(k == m){
		for(int i = 0; i < m; i++){
			cout << memo[i] << " ";
		}
		cout << "\n";
		return;
	}	

	for(int i = 0; i < n; i++){
		if(check[i]) continue;
		check[i] = 1;
		memo[k] = arr[i];
		func(k + 1);
		check[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	func(0);
	return 0;
}