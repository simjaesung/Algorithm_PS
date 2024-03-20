#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;

ll arr[1000005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		reverse(s.begin(), s.end());
		arr[i] = stol(s);
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
	return 0;
}