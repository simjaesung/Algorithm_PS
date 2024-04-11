#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int n; cin >> n;
	while (n--) {
		string a, b;
		cin >> a >> b;
		int A[26] = { 0 }, B[26] = { 0 };

		for (auto& x : a) A[x - 'a']++;
		for (auto& s : b) B[s - 'a']++;

		int check = 1;
		for (int i = 0; i < 26; i++) {
			if (A[i] != B[i]) {
				check = 0;
				break;
			}
		}
		if (check) cout << "Possible" << '\n';
		else cout << "Impossible" << '\n';
	}
	
	return 0;

}