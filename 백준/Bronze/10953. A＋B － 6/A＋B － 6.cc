#include <iostream>

using namespace std;

int main()
{
	int n, A, B;
	cin >> n;
	char comma;

	while (n-- > 0) {
		cin >> A >> comma >> B;
		cout << A + B << endl;
	}
	
	return 0;
}