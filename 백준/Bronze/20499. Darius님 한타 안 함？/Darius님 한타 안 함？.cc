#include<iostream>
using namespace std;
int arr[3];
int main()
{
	string s; cin >> s;
	int val = 0, idx = 0;
	for (auto x : s) {
		if (x != '/') {
			val *= 10;
			val += x - '0';
		}
		else {
			arr[idx++] = val;
			val = 0;
		}
	}
	arr[idx] = val;
	if (arr[0] + arr[2] < arr[1] || arr[1] == 0) cout << "hasu";
	else cout << "gosu";
	
	return 0;
}