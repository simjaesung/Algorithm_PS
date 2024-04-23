#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[55][15];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++) cin >> arr[i][j];
	}
	//타자 순서
	int b[] = { 1,2,3,4,5,6,7,8 };
	int ans = 0;

	do {
		int score = 0;
		int turn = 0; int idx = 0;

		for (int ing = 1; ing <= n; ing++) {
			int out = 0; //아웃은 이닝별로
			int cnt = 0; //홈에들어온 주자들

			vector<int>j; //주자

			while (out < 3) {
				turn %= 9; idx %= 8;
				int t, tmp; //타자 순서와 무슨 안타를 쳤는지

				if (turn == 3) t = 1; //4번타자
				else t = b[idx++] + 1;
				turn++;

				tmp = arr[ing][t];
				
				if (tmp == 0) {
					out++; continue;
				}
				//타자친 주자 진루
				j.push_back(tmp);

				//진루해있던 타자들 진루
				for (int i = cnt; i < j.size()-1; i++) j[i] += tmp;

				//홈에 들어온 타자 표시
				for (int i = cnt; i < j.size(); i++) {
					if (j[i] > 3) cnt++;
				}
			}
			score += cnt;

		}
		ans = max(score, ans);

	} while (next_permutation(b, b + 8));

	cout << ans;
	return 0;
}