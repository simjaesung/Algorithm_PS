#include<iostream>
using namespace std;

int num[20];
int check[6];
int n;

void go(int index, int select)
{
	if (select == 6) {
		for (int i = 0; i < 6; i++) {
			cout << num[check[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	if (index >= n) return;

	check[select] = index;
	go(index + 1, select + 1);
	go(index + 1, select);
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	while (1) {
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) cin >> num[i];
		go(0, 0);

		cout << '\n';
	}
	return 0;
}