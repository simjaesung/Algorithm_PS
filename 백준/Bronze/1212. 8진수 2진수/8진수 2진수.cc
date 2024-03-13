#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	string oct,bin;
	cin >> oct;

	for (auto x : oct) {
		int val = x - '0';
		int k = 4;
		while (k > 0) {
			if (val / k > 0) bin += '1';
			else bin += '0';
			val %= k;
			k /= 2;
		}
	}

	int init = 0;

	for (int i = 0; i < bin.length(); i++)
		if (bin[i] == '0') init++;
		else break;

	if (init == bin.length()) init--;

	for (int i = init; i < bin.length(); i++)
		cout << bin[i];

	return 0;
}