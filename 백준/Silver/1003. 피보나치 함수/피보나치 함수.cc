#include<iostream>
using namespace std;
typedef long long ll;
ll arr[50][2];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	arr[0][0] = 1;
	arr[1][1] = 1;

	for (int i = 2; i <= 40; i++) {
		arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
		arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
	}

	int n; cin >> n;
	while (n--) {
		int val; cin >> val;
		cout << arr[val][0] << ' ' << arr[val][1] << '\n';
	}

	return 0;
}