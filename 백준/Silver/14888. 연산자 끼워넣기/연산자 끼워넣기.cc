#include<iostream>
#include<limits.h>
using namespace std;

int max_ans = INT_MIN;
int min_ans = INT_MAX;
int n;
int u[4], num[15], s[15];
//+-x/

void go(int select)
{
	if (select == n - 1) {
		int val = num[0];
		for (int i = 1; i < n; i++) {
			if (s[i - 1] == 0) val += num[i];
			else if (s[i - 1] == 1) val -= num[i];
			else if (s[i - 1] == 2) val *= num[i];
			else if (s[i - 1] == 3) val /= num[i];
		}

		max_ans = max(max_ans, val);
		min_ans = min(min_ans, val);

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (u[i] == 0) continue;
		u[i]--; s[select] = i;
		go(select + 1);
		u[i]++;
	}
}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	for (int i = 0; i < 4; i++) cin >> u[i];

	go(0);
	cout << max_ans << '\n';
	cout << min_ans << '\n';
	
	return 0;
}