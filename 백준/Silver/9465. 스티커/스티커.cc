#include<iostream>
using namespace std;

int score[2][100001] = {0};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i <=1; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> score[i][j];
			}
		}

		for (int j = 2; j <= n; j++) {
			if (j == 2) {
				score[0][j] += score[1][j - 1];
				score[1][j] += score[0][j - 1];
			}
			else {
				score[0][j] += max(score[1][j - 1], score[1][j - 2]);
				score[1][j] += max(score[0][j - 1], score[0][j - 2]);
			}
		}
		cout << max(score[0][n], score[1][n]) << '\n';
	}

	
	return 0;
}