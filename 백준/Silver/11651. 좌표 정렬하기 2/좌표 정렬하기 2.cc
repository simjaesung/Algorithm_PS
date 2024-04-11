#include<iostream>
#include<algorithm>
using namespace std;

pair<int, int> arr[100005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;
	}
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		cout << arr[i].second << ' ' << arr[i].first << '\n';
	}

	return 0;
}