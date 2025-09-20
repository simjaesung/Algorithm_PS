#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int val, sum = 0;
	vector<int> v;
	for(int i = 0; i < 5; i++){
		cin >> val; 
		sum += val;
		v.push_back(val);
	}

	sort(v.begin(), v.end());
	cout << sum / 5 << "\n";
	cout << v[2];
	return 0;
}