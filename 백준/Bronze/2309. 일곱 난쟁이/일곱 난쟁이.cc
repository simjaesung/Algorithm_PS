#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int arr[9];
	int sum = 0;
	for(int i = 0; i < 9; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	int diff = sum - 100;
	sort(arr, arr + 9);
	int idx1, idx2;
	for(int i = 0; i < 9; i++){
		for(int j = i + 1; j < 9; j++){
			if(arr[i] + arr[j] == diff){
				idx1 = i;
				idx2 = j;
			}
		}
	}

	for(int i = 0; i < 9; i++){
		if(i != idx1 && i != idx2){
			cout << arr[i] << "\n";
		}
	}
	return 0;
}