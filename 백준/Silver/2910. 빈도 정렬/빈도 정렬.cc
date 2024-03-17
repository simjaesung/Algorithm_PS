#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[1005];

bool compare(const pair<int, int>& a, const pair<int, int>& b){
	//두번째 인자가 큰게 앞으로
	return a.second > b.second;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, c;
	cin >> n >> c;

	//등장 순서를 저장
	vector<int>turn;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		//등장 순서를 저장
		int check = 0;
		for (int s = 0; s < turn.size(); s++) {
			if (arr[i] == turn[s]) {
				check = 1; break;
			}
		}
		if (!check) turn.push_back(arr[i]);
	}
	
	vector<pair<int, int>>v;

	//등장 순서 순으로 개수 체크
	for (auto x : turn) {
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			if (x == arr[i]) tmp++;
		}
		v.push_back(make_pair(x, tmp));
	}

	stable_sort(v.begin(), v.end(), compare);

	for (auto x : v) {
		for (int i = 0; i < x.second; i++) cout << x.first << ' ';
	}
	
	return 0;
}