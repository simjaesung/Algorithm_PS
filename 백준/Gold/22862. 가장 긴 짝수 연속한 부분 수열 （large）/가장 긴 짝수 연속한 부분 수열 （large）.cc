#include<iostream>
using namespace std;

int n, k;
int tmp, s, e, ans, arr[1000005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k; 
	for (int i = 0; i < n; i++) cin >> arr[i];
	//tmp는 지운 개수
	while (s < n && e < n) {
		if (tmp <= k) {
			if (arr[e++] % 2 == 1) tmp++;
		}
		else{
			if (arr[s++] % 2 == 1) tmp--;
		}
		ans = max(ans, e - s - tmp);
	}
	cout << ans;

	return 0;
}