#include <iostream>
using namespace std;
int h,w,x,y;
int arr[605][605];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> h >> w >> x >> y;
	for(int i = 0; i < h+x; i++){
		for(int j = 0; j < w+y; j++) cin >> arr[i][j];
	}
	
	for(int i = x; i < h; i++){
		for(int j = y; j < w; j++) arr[i][j] -= arr[i-x][j-y];
	}
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++) cout << arr[i][j] << ' ';
		cout << '\n';
	}
	
	
	return 0;
}