#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s[5];
	for (int i = 1; i <= 4; i++)
		cin >> s[i];

	//톱니바퀴가 맞닿는 부분 idx
	int t1_r = 2;
	int t2_l = 6, t2_r = 2;
	int t3_l = 6, t3_r = 2;
	int t4_l = 6;
	
	int k; cin >> k;
	while (k--) {
		int tnum, dir;
		cin >> tnum >> dir;
		int rotate[6] = { 0 };
		//0: 그대로 / 1 : 시계 / -1: 반시계
		if (tnum == 1) {
			//시계방향
			if (dir == 1) rotate[1] = 1;
			//반시계방향
			else rotate[1] = -1;

			if (s[1][t1_r] != s[2][t2_l]) rotate[2] = -rotate[1];
			if (s[2][t2_r] != s[3][t3_l]) rotate[3] = -rotate[2];
			if (s[3][t3_r] != s[4][t4_l]) rotate[4] = -rotate[3];
		}
		else if (tnum == 2) {
			//시계방향
			if (dir == 1) rotate[2] = 1;
			//반시계방향
			else rotate[2] = -1;

			if (s[1][t1_r] != s[2][t2_l]) rotate[1] = -rotate[2];
			if (s[2][t2_r] != s[3][t3_l]) rotate[3] = -rotate[2];
			if (s[3][t3_r] != s[4][t4_l]) rotate[4] = -rotate[3];
		}
		else if (tnum == 3) {
			//시계방향
			if (dir == 1) rotate[3] = 1;
			//반시계방향
			else rotate[3] = -1;

			if (s[2][t2_r] != s[3][t3_l]) rotate[2] = -rotate[3];
			if (s[3][t3_r] != s[4][t4_l]) rotate[4] = -rotate[3];
			if (s[1][t1_r] != s[2][t2_l]) rotate[1] = -rotate[2];
			
		}
		else if (tnum == 4) {
			//시계방향
			if (dir == 1) rotate[4] = 1;
			//반시계방향
			else rotate[4] = -1;

			if (s[3][t3_r] != s[4][t4_l]) rotate[3] = -rotate[4];
			if (s[2][t2_r] != s[3][t3_l]) rotate[2] = -rotate[3];
			if (s[1][t1_r] != s[2][t2_l]) rotate[1] = -rotate[2];
		}

		for (int i = 1; i <= 4; i++) {
			if (rotate[i] == 1) {
				if (i == 1) t1_r = ((t1_r - 1) + 8) % 8;
				else if (i == 2) {
					t2_r = ((t2_r - 1) + 8) % 8;
					t2_l = ((t2_l - 1) + 8) % 8;
				}
				else if (i == 3) {
					t3_r = ((t3_r - 1) + 8) % 8;
					t3_l = ((t3_l - 1) + 8) % 8;
				}
				else t4_l = ((t4_l - 1) + 8) % 8;
			}
			else if (rotate[i] == -1) {
				if (i == 1) t1_r = (t1_r + 1) % 8;
				else if (i == 2) {
					t2_r = (t2_r + 1) % 8;
					t2_l = (t2_l + 1) % 8;
				}
				else if (i == 3) {
					t3_r = (t3_r + 1) % 8;
					t3_l = (t3_l + 1) % 8;
				}
				else t4_l = (t4_l + 1) % 8;
			}
			else continue;
		}
	}

	int ans = 0;
	if (s[1][((t1_r - 2) + 8) % 8] == '1') ans += 1;
	if (s[2][(t2_l + 2) % 8] == '1') ans += 2;
	if (s[3][(t3_l + 2) % 8] == '1') ans += 4;
	if (s[4][(t4_l + 2) % 8] == '1') ans += 8;

	cout << ans;


	return 0;
}