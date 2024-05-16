#include<iostream>
#include<algorithm>
using namespace std;

int num[10], a[10];

void go(int index, int n, int m)
{
	if (index == m){
		for (int i = 0; i < m; i++)
			cout << num[a[i]] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		a[index] = i;
		go(index + 1, n, m);
	}
}



int main()
{
	ios::sync_with_stdio(0);
	cout.tie(nullptr);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	go(0, n, m);
	return 0;
}