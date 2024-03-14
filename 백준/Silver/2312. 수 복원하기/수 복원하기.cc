#include<iostream>
#include<algorithm>
using namespace std;
int arr[100005], c[100005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 2; i <= 100000; i++) {
		if (!arr[i]) {
			for (int j = i * 2; j <= 100000; j += i) arr[j] = 1;
		}
	}

	int n; cin >> n;
	while (n--) {
		int val; cin >> val;
		fill(c, c + 100005, 0);
		for (int i = 2; i <= 100000; i++) {
			if (!arr[i]) {
				while (val > 1) {
					if (val % i == 0) {
						c[i]++; 
						val /= i;
					}
					else break;
				}
			}
		}

		for (int i = 2; i < 100005; i++) {
			if (c[i] != 0) {
				cout << i << ' ' << c[i] << '\n';
			}
		}
	}

	return 0;
}