#include <iostream>
#include<math.h>

using namespace std;

int main()
{
	int A, B, m, val;
	cin >> A >> B >> m;
	int arr[21] = { 0 };
	int ten = 0, cnt = 0;

	while (m-- > 0) {
		cin >> val;
		ten += pow(A, m) * val;
	}
	
	while (ten != 0) {
		arr[cnt++] = ten % B;
		ten /= B;
	}

	for (int i = cnt - 1; i >= 0;i--)
		cout << arr[i] << ' ';

	return 0;
}