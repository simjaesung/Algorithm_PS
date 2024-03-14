#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string arr[20005];
vector<string>v;

bool compare(const string& a, const string& b)
{
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	return a < b;
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n, compare);
	v.push_back(arr[0]);

	for (int i = 1; i < n; i++) {
		if (v[v.size() - 1] == arr[i]) continue;
		else v.push_back(arr[i]);
	}
	for (auto x : v) cout << x << '\n';
	return 0;
}