#include<iostream>
using namespace std;

int arr[10001];

bool next_purmutaion(int* a, int n)
{
	int j = n;
	while (j > 1 && a[j - 1] >= a[j]) j--;
	if (j <= 1) return false;

	int i = n;
	while (a[i] <= a[j - 1]) i--;
	swap(a[j - 1], a[i]);
	i = n;
	while (i > j) swap(a[j++], a[i--]);
	return true;
}



int main()
{
	ios::sync_with_stdio(0); cin.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	if (next_purmutaion(arr, n)) {
		for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
	}
	else cout << -1;
	
	return 0;
}