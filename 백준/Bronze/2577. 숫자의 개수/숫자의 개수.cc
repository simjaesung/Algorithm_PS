#include <iostream>
using namespace std;
int arr[10];
int main() {
	int a,b,c;
	cin >> a >> b >> c;
	int result = a * b * c;

	while(result > 0){
		arr[result % 10]++;
		result /= 10;
	}

	for(int k : arr) cout << k << "\n";
	return 0;
}