#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

char arr[20], memo[20];
unordered_map<char,int> moum;
int l,c;

void setHash(){
	moum['a'] = 1;
	moum['e'] = 1;
	moum['i'] = 1;
	moum['o'] = 1;
	moum['u'] = 1;
}

bool check(){
	int m = 0,j = 0;
	for(int i = 0; i < l; i++){
		char k = memo[i];
		if(moum[k]) m++;
		else j++;
	}
	return m >=1 && j >=2;
}

void go(int k, int idx){
	if(k == l && check()){
		for(int i = 0; i < l; i++) cout << memo[i];
		cout << "\n";
		return;
	}

	for(int i = idx; i < c; i++){
		memo[k] = arr[i];
		go(k + 1, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> c;
	for(int i = 0; i < c; i++) cin >> arr[i];
	sort(arr, arr + c);
	setHash();
	go(0,0);
	return 0;
}