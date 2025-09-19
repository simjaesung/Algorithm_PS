#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;

	vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	sort(v.begin(), v.end());
	
	for(int k : v) 
		cout << k << " ";
	
	return 0;
}