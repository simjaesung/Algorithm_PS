#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n; cin >> n;
	int M, N, x, y, ans;

	while (n--) {
		cin >> M >> N >> x >> y;
		ans = -1;

		for (int i = x % M; i <= N*M; i += M) {
			if (i == 0) continue;
			if (i % N == y % N) {
				ans = i;
				break;
			}
		}
		cout << ans<< '\n';
	}
	return 0;
}