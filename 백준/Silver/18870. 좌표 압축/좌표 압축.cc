#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[1000005];
vector<int>v,v2;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v2.push_back(arr[i]);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (v.empty()) v.push_back(arr[i]);
		else if(v[v.size() - 1] != arr[i]) v.push_back(arr[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << lower_bound(v.begin(), v.end(), v2[i]) - v.begin() << ' ';
	}
	
	return 0;
}