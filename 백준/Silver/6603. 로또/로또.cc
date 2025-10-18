#include <iostream>

using namespace std;
int n, arr[50], memo[50];

void go(int k, int idx){
	if(k == 6){
		for(int i = 0; i < 6; i++) cout << memo[i] << " ";
		cout << "\n";
		return;
	}

	for(int i = idx; i < n; i++){
		memo[k] = arr[i];
		go(k + 1, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(true){
		cin >> n;
		if(n == 0) break;
		for(int i = 0; i < n; i++) cin >> arr[i];
		go(0,0);
		cout << "\n";
	}
	return 0;
}