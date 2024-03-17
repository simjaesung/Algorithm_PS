#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];
bool check[2000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n,sum,ans = 0; 
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> sum;

	for (int i = 0; i < n; i++) {
		if (sum - arr[i] > 0 && check[sum - arr[i]]) ans++;
		check[arr[i]] = true;
	}

	cout << ans;
	return 0;
}