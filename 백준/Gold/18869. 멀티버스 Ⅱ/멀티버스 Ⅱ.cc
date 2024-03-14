#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, ans;
int arr[105][10005];
vector<vector<int>>v;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}
	//좌표압축
	for (int i = 0; i < n; i++) {
		vector<int>tmp1,tmp2;
		for (int j = 0; j < m; j++) tmp1.push_back(arr[i][j]);
		sort(tmp1.begin(), tmp1.end());
		for (int j = 0; j < m; j++) {
			int idx = lower_bound(tmp1.begin(), tmp1.end(), arr[i][j]) - tmp1.begin();
			tmp2.push_back(idx);
		}
		v.push_back(tmp2);
	}

	for(int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int check = 0;
			for (int k = 0; k < m; k++) {
				if (v[i][k] != v[j][k]) check = 1;
			}
			if (!check) ans++;
		}
	}
	cout << ans;
	return 0;
}