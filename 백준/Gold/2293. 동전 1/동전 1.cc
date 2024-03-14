#include<iostream>
using namespace std;

int m[105], d[100005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n,k; 
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> m[i];

	for (int i = 0; i < n; i++) {
		d[m[i]]++;
		for (int j = m[i] + 1; j <= k; j++) d[j] += d[j - m[i]];
	}

	cout << d[k];

	return 0;
}
