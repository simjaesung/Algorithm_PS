#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[100005][2];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back(make_pair(a * 100 + b, c * 100 + d));
	}
	sort(v.begin(), v.end());

	int end = 0, start = 0; //현재 고른 꽃의 피고 지는 날짜
	int nidx = 0; // 첫번째꽃을 고르고 이후의 idx
	for (int i = 0; i < n; i++) {
		if (v[i].first <= 301) {
			if (end < v[i].second) {
				start = v[i].first;
				end = v[i].second;
			}
			nidx = i;
		}
		else break;
	}

	//3월 1일에 꽃이 없다면 
	if (end <= 301) {
		cout << 0;
		return 0;
	}

	int ans = 1; // 1개의 꽃을 고름

	while (end < 1201) {
		int maxend = end; //이전 고른 꽃이 지기 전에 피고 가장 늦께 지는 꽃
		for (int i = nidx + 1; i < n; i++) {
			if (v[i].first <= end && v[i].second > maxend)
				maxend = v[i].second;
		}
		if (maxend == end) {
			cout << 0;
			return 0;
		}
		ans++;
		end = maxend;
	}
	
	cout << ans;
	return 0;
}