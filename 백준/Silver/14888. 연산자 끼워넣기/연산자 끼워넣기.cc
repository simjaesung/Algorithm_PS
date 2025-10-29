#include <iostream>
#include <climits>
using namespace std;

int max_ans = INT_MIN;
int min_ans = INT_MAX;
int n, arr[11], op[4];

void input(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < 4; i++) cin >> op[i];
}

void go(int k, int val){
	if(k == n){
		max_ans = max(val ,max_ans);
		min_ans = min(val ,min_ans);
		return;
	}

	for(int i = 0; i < 4; i++){
		if(!op[i]) continue;
		op[i]--;
		if(i == 0) go(k + 1, val + arr[k]);
		if(i == 1) go(k + 1, val - arr[k]);
		if(i == 2) go(k + 1, val * arr[k]);
		if(i == 3) go(k + 1, val / arr[k]);
		op[i]++;
	}
}

int main() {
	input();
	go(1,arr[0]);
	cout << max_ans << "\n" << min_ans;
	return 0;
}