#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	int maxX, minX, maxY, minY;
	maxX = -10000; minX = 10000;
	maxY = -10000; minY = 10000;

	while (n--) {
		int x, y;
		cin >> x >> y;
		maxX = max(maxX, x);
		maxY = max(maxY, y);
		minX = min(minX, x);
		minY = min(minY, y);
	}

	cout << (maxX - minX) * (maxY - minY);
	return 0;
}