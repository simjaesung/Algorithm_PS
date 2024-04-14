#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i(100);
	while (i-- > 0) {
		char s[101];
		cin.getline(s, 101);
		cout << s << '\n';
	}
	return 0;
}