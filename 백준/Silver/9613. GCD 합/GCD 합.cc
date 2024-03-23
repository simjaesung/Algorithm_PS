#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() 
{
	int n, t ,val;
    long long ans;
	cin >> n;

	while (n--) {
		ans = 0;
		cin >> t;
		vector<int>list(t);
		for (int i = 0; i < t; i++) {
			cin >> val;
			list[i] = val;
		}

		for (int i = 0; i < t-1; i++) {
			for (int j = i + 1; j < t; j++) {
				ans += gcd(list[i], list[j]);
			}
		}

		cout << ans << '\n';
	}
}