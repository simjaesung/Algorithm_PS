#include <iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	string biniary;
	cin >> biniary;

	int len = biniary.length();
	int init = 0;

	if (len % 3 == 2) {
		cout << ((biniary[0] - '0') * 2) + (biniary[1] - '0');
		init = 2;
	}
	else if (len % 3 == 1) {
		cout << biniary[0];
		init = 1;
	}

	for (int i = init; i < len; i += 3) {
		cout << ((biniary[i] - '0') * 4) + ((biniary[i + 1] - '0') * 2) + ((biniary[i + 2] - '0') * 1);
	}

	cout << '\n';

	return 0;
}