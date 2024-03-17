#include<iostream>
using namespace std;

int main()
{
	int ans[6] = { 1, 1, 2, 2, 2, 8 };
	int input[6] = { 0 };
	for (int i = 0; i < 6; i++) cin >> input[i];

	for (int i = 0; i < 6; i++) cout << ans[i] - input[i] << ' ';
	return 0;
}