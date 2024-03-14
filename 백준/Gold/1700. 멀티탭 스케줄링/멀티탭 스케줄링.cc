#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<queue<int>>v(105); //물건들의 다음 순위
vector<int>cs; //콘센트에 꽂혀있는것 
int arr[105];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> arr[i];
		//물건의 할당된 순서를 push
		v[arr[i]].push(i);
	}
	int ans = 0;

	for (int i = 1; i <= k; i++) {
		if (cs.size() < n) {
			//이미 꽂혀있는건지 확인 
			int check = 0;
			for (int j = 0; j < cs.size(); j++) {
				if (arr[i] == cs[j]) check = 1;
			}
			if (!check) cs.push_back(arr[i]);
			v[arr[i]].pop();
		}
		else{
			//콘세트에 꽂혀있는지 확인하기
			int check = 0;
			for (int j = 0; j < cs.size(); j++) {
				if (arr[i] == cs[j]) check = 1;
			}
			if (check) {
				v[arr[i]].pop();
				continue;
			}

			int maxturn = 0; //제일 늦게 사용하는 물건
			int maxval = 0; //그 물건의 번호
			for (int j = 0; j < cs.size(); j++) {
				//더이상 꽂을 일이 없을 때
				if (v[cs[j]].empty()) {
					maxval = cs[j];
					break;
				}
				//제일 늦게 할당 받는 물건 확인 
				else if (v[cs[j]].front() > maxturn) {
					maxval = cs[j];
					maxturn = v[cs[j]].front();
				}
			}

			//콘센트 뽑기
			for (int j = 0; j < cs.size(); j++) {
				if (cs[j] == maxval) {
					cs[j] = arr[i];
					v[arr[i]].pop();
					ans++;
				}
			}
		}
	}

	cout << ans;

	return 0;
}