#include <iostream>
using namespace std;

int main()
{
	int n, A, B;
	cin >> n;
	int i(0);

	while (i++ < n) {
		cin >> A >> B;
		cout << "Case #" << i << ": " << A + B << endl;
	}
	
	return 0;
}