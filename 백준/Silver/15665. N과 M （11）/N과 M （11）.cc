#include<iostream>
#include<algorithm>
using namespace std;

int n, m, a[10],num[10];

void go(int index)
{
	if (index == m) {
		for (int i = 0; i < m; i++) cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (tmp == num[i]) continue;
		a[index] = num[i];
		tmp = num[i];
		go(index + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	go(0);
	
	return 0;
}