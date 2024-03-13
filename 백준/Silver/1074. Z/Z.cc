#include<iostream>
using namespace std;

int z(int n, int r, int c) 
{
	if (n == 0) return 0;
	int mid = (1 << (n - 1));
	int val = mid * mid;
	if (r >= mid && c >= mid) return 3 * val + z(n - 1, r - mid, c - mid);
	if (r >= mid && c < mid) return 2 * val + z(n - 1, r - mid, c);
	if (r < mid && c >= mid) return val + z(n - 1, r, c - mid);
	else return z(n - 1, r, c);
}

int main()
{
	int n, r, c;
	cin >> n >> r >> c;
	cout << z(n, r, c);
	return 0;
}