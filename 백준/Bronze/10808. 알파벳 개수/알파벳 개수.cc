#include<iostream>
using namespace std;

int main()
{
	int alpha[26] = { 0 };

	string s;
	cin >> s;

	for (auto& x : s) alpha[x - 'a']++;
	for (auto& x : alpha) cout << x << ' ';
	return 0;
}