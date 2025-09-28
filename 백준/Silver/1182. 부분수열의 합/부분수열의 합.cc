#include <iostream>
#include <algorithm>
using namespace std;
int n,s,arr[25],ans;

void func(int sum, int idx){
	if(idx == n){
		if(sum == s) ans++;
		return;
	}
	
	func(sum + arr[idx], idx + 1);
	func(sum, idx + 1);
}

int main() {
	cin >> n >> s;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	
	func(0,0);
	if(s == 0) ans--;
	cout << ans;
	return 0;
}