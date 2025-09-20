#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[20];
	for(int i = 1; i <= 20; i++) arr[i-1] = i;

	int a,b;
	for(int i = 0; i < 10; i++){
		cin >> a >> b;
		while(a < b){
			swap(arr[a-1], arr[b-1]);
			a++; b--;
		}
	}

	for(int i = 1; i <= 20; i++){
		cout << arr[i - 1] << " ";
	}

	return 0;
}