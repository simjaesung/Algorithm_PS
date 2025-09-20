#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];

int main() {
	int room;
	cin >> room;

	while(room > 0){
		if(room % 10 == 6) arr[9]++;
		else arr[room % 10]++;
		room /= 10;
	}

	if(arr[9] % 2 ==1) arr[9] = arr[9] / 2 + 1;
	else arr[9] = arr[9] / 2;

	cout << *max_element(arr,arr + 10);
	return 0;
}