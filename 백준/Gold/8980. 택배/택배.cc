#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int h[2005][2005]; //무게 정보 저장
int arr[2005];
int n, k, m;
bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k >> m;
	vector<pair<int, int>>v;

	while (m--) {
		int s, e, l;
		cin >> s >> e >> l;
		h[s][e] = l;
		v.push_back({ s,e });
	}

	sort(v.begin(), v.end(),compare);

	int ans = 0;

	for (int i = 0; i < v.size(); i++) {
		int a, b, m; //시작 끝 무게
		a = v[i].first;	b = v[i].second; m = h[a][b];

		int tmp = 0;
		//구간에 실려있는 무게중 가장 큰 값
		for (int i = a; i < b; i++) tmp = max(tmp, arr[i]);
		//m을 실을 수 있으면 싣고 아니면 남은 칸만큼 실어야함
		tmp = min(k - tmp, m);
		//싣는 과정
		for (int i = a; i < b; i++) arr[i] += tmp;
		ans += tmp;
	}

	cout << ans;
	return 0;
}