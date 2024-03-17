#include<iostream>
#include<algorithm>
using namespace std;
int arr[5];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 5; i++) cin >> arr[i];
	
	while (1) {
		for (int i = 0; i < 4; i++) {
			if (arr[i] > arr[i + 1]) {
				int check = 1;
				swap(arr[i], arr[i + 1]);

				for (int j = 0; j < 5; j++) {
					if (arr[j] != j + 1) check = 0;
					cout << arr[j] << ' ';
				}
				if (check) return 0;
				cout << '\n';
			} 
		}
	}
	return 0;
}