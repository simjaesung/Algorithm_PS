#include<iostream>
using namespace std;

int main()
{
	int arr[4];
	int cnt,n = 3;

	while (n--) {
		cnt = 0;
		for (int i = 0; i < 4; i++) cin >> arr[i];
		for (int i = 0; i < 4; i++) if (arr[i] == 1) cnt++;

		switch (cnt)
		{
		case 0:
			cout << 'D'; break;
		case 1:
			cout << 'C'; break;
		case 2:
			cout << 'B'; break;
		case 3:
			cout << 'A'; break;
		case 4:
			cout << 'E'; break;
		}
		cout << '\n';
	}
	
	return 0;
}