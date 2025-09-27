#include <iostream>
using namespace std;
int n,m,check[10];

void func(int s, int cnt){
	if(cnt == m){
		for(int i = 1; i <= n; i++){
			if(check[i]) cout << i << " ";
		}
		cout << "\n";
		return;
	}

	for(int i = s; i <= n; i++){
		if(check[i]) continue;
		check[i] = 1;
		func(i + 1, cnt + 1);
		check[i] = 0;
	}
}

int main() {
	cin >> n >> m;
	func(1,0);
	return 0;
}