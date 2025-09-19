#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int input, result;
	string res = "DCBAE";

	for(int i = 0; i < 3; i++){
		result = 0;
		for(int k = 0; k < 4; k++){
			cin >> input;
			result += input;
		}
		cout << res[result] << "\n";
	}
}