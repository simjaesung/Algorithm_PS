#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	while (getline(cin,s))
	{
		int lower = 0, upper = 0, num = 0, space = 0;
		for (auto x : s) {
			if (x >= 'a' && x <= 'z') lower++;
			else if (x >= 'A' && x <= 'Z') upper++;
			else if (x >= '0' && x <= '9') num++;
			else if (x == ' ') space++;
		}
		cout << lower << ' ' << upper << ' ' << num << ' ' << space <<'\n';
	}

	return 0;
}

