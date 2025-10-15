#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int arr[10], memo[10], isused[10];

void go(int k){
	if(k == m){
		for(int i = 0; i < m; i++) cout << memo[i] << " ";
		cout << "\n";
		return;
	}

	int tmp = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] != tmp && !isused[i]){
			memo[k] = arr[i];
			isused[i] = 1;
			go(k + 1);
			tmp = arr[i];
			isused[i] = 0;
		}
	}
	
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr,arr + n);
	go(0);
	return 0;
}