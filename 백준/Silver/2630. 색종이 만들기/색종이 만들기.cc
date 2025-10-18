#include <iostream>
using namespace std;

int n,w,b;
int arr[130][130];

void input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) cin >> arr[i][j];
	}
}

bool isAllColored(int x1, int y1, int x2, int y2){
	for(int i = x1; i < x2; i++){
		for(int j = y1; j < y2; j++) {
			if(arr[i][j] != arr[x1][y1]) return false; 
		}
	}
	return true;
}

void go(int x1, int y1, int x2, int y2){
	if(isAllColored(x1,y1,x2,y2)){
		if(arr[x1][y1]) b++;
		else w++;
		return;
	}
	int len = (x2 - x1) / 2;
	go(x1,y1,x1+len, y1+len);
	go(x1,y1+len,x1+len,y2);
	go(x1+len,y1,x2,y1+len);
	go(x1+len,y1+len,x2,y2);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	go(0,0,n,n);
	cout << w << "\n" << b;
}