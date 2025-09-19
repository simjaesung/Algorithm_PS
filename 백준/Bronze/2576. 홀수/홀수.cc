#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int minVal = 100;
	int val, sum = 0;
	for(int i = 0; i < 7; i++){
		cin >> val;
		if(val % 2 == 1){
			sum += val;
			minVal = min(val,minVal);
		}
	}

	if(sum == 0){
		cout << -1;
		return 0;
	}

	cout << sum << "\n" << minVal;
	return 0;
	
}