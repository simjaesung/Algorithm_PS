#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, pow = 1;
	cin >> n;
	
	vector<int>arr(n + 1);

	for (int i = 1; i <= n; i++) {
		arr[i] = i;
		for (int j = 1; j * j <= i; j++) {
			arr[i] = min(arr[i], arr[i - j * j] + 1);
		}
	}

	cout << arr[n];
	
	return 0;
}