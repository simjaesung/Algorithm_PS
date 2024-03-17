#include<iostream>
using namespace std;
int arr[20];

int main()
{
	arr[0] = 2;
	for (int i = 1; i <= 15; i++) arr[i] = 2 * arr[i - 1] - 1;
	int n; cin >> n;
	cout << arr[n] * arr[n];
	
	return 0;
}