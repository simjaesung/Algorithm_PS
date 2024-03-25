#include<iostream>
#include<string>

using namespace std;

int main()
{
	string arr[4];

	for (int i = 0; i < 4; i++)
		cin >> arr[i];

	arr[0] += arr[1];
	arr[2] += arr[3];

	cout << stol(arr[0])+stol(arr[2]);
	
	
	return 0;
}