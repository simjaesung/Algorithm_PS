#include <iostream>
using namespace std;


int main()
{
	int n, A, B;

	int i(0);
	cin >> n;

	while (i++ < n) {
		cin >> A >> B;
		cout << A + B << endl;
	}
	return 0;
}