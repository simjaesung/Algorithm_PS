#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int arr[10], isUsed[10], memo[10];

void func(int k, int idx){
	if(k == m){
		for(int i = 0; i < m; i++){
			cout << memo[i] << " ";
		}
		cout << "\n";
		return;
	}

	for(int i = idx; i < n; i++){
		if(isUsed[i]) continue;
		memo[k] = arr[i];
		isUsed[i] = 1;
		func(k + 1, i + 1);
		isUsed[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	func(0,0);
	return 0;
}