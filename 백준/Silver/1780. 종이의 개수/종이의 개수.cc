#include <iostream>
using namespace std;
int arr[5000][5000];
int n;
int ans_zero, ans_one, ans_mone;

void input(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
}

void plusAns(int x,int y){
	if(arr[x][y] == 0) ans_zero++;
	else if(arr[x][y] == 1) ans_one++;
	else ans_mone++;
}

bool isSame(int x1, int y1, int x2, int y2){
	int k = arr[x1][y1];
	for(int i = x1; i < x2; i++){
		for(int j = y1; j < y2; j++){
			if(arr[i][j] != k) return false;
		}
	}
	return true;
}

void func(int x1, int y1, int x2, int y2){
	if(isSame(x1,y1,x2,y2)) plusAns(x1,y1);
	else{
		int gap = x2 - x1;
		for(int i = x1; i < x2; i+=gap/3){
			for(int j = y1; j < y2; j+=gap/3){
				func(i,j,i+gap/3,j+gap/3);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	func(0,0,n,n);
	cout << ans_mone << "\n";
	cout << ans_zero << "\n";
	cout << ans_one << "\n";
	return 0;
}