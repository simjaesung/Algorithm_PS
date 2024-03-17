#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, val, s, e, ans;
vector<int>v;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> val; v.push_back(val);
	}

	sort(v.begin(), v.end());

	s = 1, e = v[n - 1], ans = 0;

	while (s <= e) {
		int mid = (s + e) / 2;
		long long tmp = 0; //자른 나무들의 합
		for (int i = 0; i < n; i++) {
			if (v[i] < mid) continue;
			tmp += v[i] - mid;
		}
		//목표치보다 적게 자르면 
		if (tmp < m) e = mid - 1; // 높이를 낮게 설정
		//목표치 보다 많이 자르면 
		else {
			ans = mid;
			s = mid + 1; //더 길게 잘라도됨
		}
		
	}
	cout << ans;
	return 0;
}