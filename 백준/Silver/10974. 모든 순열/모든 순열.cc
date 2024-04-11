#include<iostream>
#include<algorithm>

using namespace std;

bool next_p(int* a, int n)
{
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i--;
	if (i <= 0) return false;
	int j = n - 1;
	while (a[i - 1] >= a[j]) j--;
	swap(a[i - 1], a[j]);
	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i++; j--;
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr); cout.tie(nullptr);
	int a[10];
	int n; cin >> n;

	for (int i = 0; i < n; i++)	a[i] = i + 1;
	for (int i = 0; i < n; i++)	cout << a[i] << ' ';
	cout << '\n';

	while (next_p(a, n)) cout << '\n';

	return 0;
}