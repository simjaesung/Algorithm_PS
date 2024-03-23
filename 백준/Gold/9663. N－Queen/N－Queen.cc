#include<iostream>
using namespace std;

int ans = 0;
int n;

int isused1[50], isused2[50], isused3[50];
//열 ↗대각선 ↘대각선 확인
void nqueen(int k)
{
	if (k == n) {
		ans++; return;
	}
	for (int i = 0; i < n; i++) {
		if (isused1[i] || isused2[k + i] || isused3[k - i + n - 1]) continue;
		isused1[i] = 1; 
		isused2[k + i] = 1; 
		isused3[k - i + n - 1] = 1;
		nqueen(k + 1);

		isused1[i] = 0;
		isused2[k + i] = 0;
		isused3[k - i + n - 1] = 0;
	}
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	nqueen(0);
	cout << ans;
	return 0;
}