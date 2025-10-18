#include <iostream>
#include <algorithm>
using namespace std;
int arr[10], memo[10];
int n,m;

void go(int k, int idx){
	if(k == m){
		for(int i = 0; i < m; i++) cout << memo[i] << " ";
		cout << "\n";
		return;
	}

	int val = 0;
	for(int i = idx; i < n; i++){
		if(val != arr[i]){
			memo[k] = arr[i];
			go(k + 1, i);
			val = arr[i];
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	go(0,0);
	return 0;
}