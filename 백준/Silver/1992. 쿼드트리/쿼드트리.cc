#include <iostream>
using namespace std;
int arr[65][65], n;

void input(){
	cin >> n;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < s.length(); j++) 
			arr[i][j] = s[j] - '0';
	}
}

int isSame(int a, int b, int len){
	int val = arr[a][b];
	for(int i = a; i < a + len; i++){
		for(int j = b; j < b + len; j++){
			if(arr[i][j] != val) return -1;
		}
	}
	return val;
}

void go(int a, int b, int len){
	int same = isSame(a,b,len);
	if(same != -1){
		cout << same;
		return;
	}
	int half = len / 2;
	cout << "(";
	go(a,b,half);
	go(a,b+half,half);
	go(a+half,b,half);
	go(a+half,b+half,half);
	cout << ")"; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	go(0,0,n);
	return 0;
}