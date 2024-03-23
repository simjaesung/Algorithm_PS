#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	while (1) {
		int n; cin >> n;
		if (n == -1) break;
		int sum = 0; 
		vector<int>ans;

		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				sum += i;
				ans.push_back(i);
			}
		}

		if (sum == n) {
			cout << n << " = ";
			for (int i = 0; i < ans.size() - 1; i++) {
				cout << ans[i] << " + ";
			}
			cout << ans[ans.size() - 1] << '\n';
			
		}
		else cout << n << " is NOT perfect.\n";

	}
	return 0;
}