#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[10], memo[10];

void go(int k, int idx){
	if(k == m){
		for(int i = 0; i < m; i++) cout << memo[i] << " ";
		cout << "\n";
		return;
	}

	for(int i = idx; i < n; i++){
		memo[k] = arr[i];
		go(k + 1, i);
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	go(0,0);
	return 0;
}