#include<iostream>
#include<vector>
using namespace std;
int arr[100005];
int n, ans;
vector<int>v;

int gcd(int a, int b)
{
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 1; i < n; i++) v.push_back(arr[i] - arr[i - 1]);

	int g = gcd(v[0], v[1]);
	for (int i = 2; i < v.size(); i++) g = gcd(g, v[i]);

	for (int i = 0; i < v.size(); i++) ans += (v[i] / g) - 1;

	cout << ans;
	return 0;
}