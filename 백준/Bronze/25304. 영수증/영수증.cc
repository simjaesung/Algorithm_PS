#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int sum, n;
	cin >> sum >> n;

	int val = 0;

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		val += a * b;
	}

	if (val == sum) cout << "Yes";
	else cout << "No";
	
	
	return 0;
}