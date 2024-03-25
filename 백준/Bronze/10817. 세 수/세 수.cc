#include<iostream>
#include<algorithm>
using namespace std;

int arr[3];

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	arr[0] = a; arr[1] = b; arr[2] = c;

	sort(arr, arr + 3);

	cout << arr[1];
	return 0;
}