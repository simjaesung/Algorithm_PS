#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	string s;
	cin >> s;

	int result(0);
	for (auto& n : s)
		result += (int)n -'0';
	
	cout << result;

	return 0;
}