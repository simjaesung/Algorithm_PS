#include <iostream>
using namespace std;
long ans = -1;
int n, to_n;
int num_cnt = 1;
void go(long val, int k, int last){
	if(k == num_cnt){
		if(ans != -1) return;
		if(to_n++ == n) ans = val;
		return;
	}

	for(int i = 0; i < last; i++){
		go(val * 10 + i, k + 1, i);
	}
}

int main() {
	cin >> n;
	
	if(n >= 1023){
		cout << -1;
		return 0;
	}
	
	while(ans == -1){
		for(int i = 0; i < 10; i++){
			go(i,1,i);
		}
		num_cnt++;
	}
	cout << ans;
	return 0;
}