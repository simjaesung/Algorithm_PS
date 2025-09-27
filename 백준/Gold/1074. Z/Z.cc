#include <iostream>
using namespace std;
int N,r,c,ans;

int func(int n, int r, int c){
	if(n == 0) return 0;
	int m = 1<<(n-1);
	if(r < m && c < m) return func(n-1,r,c);
	if(r < m && c >= m) return m * m + func(n-1, r, c-m);
	if(r >= m && c < m) return 2 * m * m + func(n-1, r-m, c);
	return 3 * m * m + func(n-1, r-m, c-m);
}

int main() {
	cin >> N >> r >> c;
	cout << func(N,r,c);
	return 0;
}