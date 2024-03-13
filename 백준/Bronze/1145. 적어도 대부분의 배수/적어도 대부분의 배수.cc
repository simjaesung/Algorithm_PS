#include<iostream>
#include<algorithm>
using namespace std;
int arr[5];

int main()
{	
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 5; i++) cin >> arr[i];
    
	int tmp = arr[2] * arr[3] * arr[4];
	int cnt = 1;
	while (cnt <= tmp) {
		int ans = 0;
		for (int i = 0; i < 5; i++) {
			if (cnt % arr[i] == 0) ans++;
		}
		if (ans > 2) {
			cout << cnt;
			return 0;
		}
		cnt++;
	}

	return 0;
}