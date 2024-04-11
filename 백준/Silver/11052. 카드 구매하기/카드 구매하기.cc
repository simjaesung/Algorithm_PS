#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	int N, tmp;
	cin >> N;
	int P[1001];

	for (int i = 1; i <= N; i++)
		cin >> P[i];

	for (int i = 2; i <= N; i++) {
		tmp = P[i];
		for (int j = 1; j <= i / 2; j++) {
			tmp = max(tmp, P[j] + P[i - j]);
		}
		P[i] = tmp;
	}

	cout << P[N];
	
	return 0;
}