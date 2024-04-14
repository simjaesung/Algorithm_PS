#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int student[7][2] = { 0 };
	int n, k, s, g,room = 0;
	cin >> n >> k;

	while (n--) {
		cin >> s >> g;
		student[g][s]++;
	}

	for (int i = 1; i <= 6; i++) {
		for (int j = 0; j <= 1; j++) {
			if (student[i][j] % k == 0) room += student[i][j] / k;
			else room += student[i][j] / k + 1;
		}
	}

	cout << room;
	return 0;
}