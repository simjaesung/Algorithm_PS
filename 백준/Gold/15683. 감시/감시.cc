#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

int arr[10][10];
int check[10][10];
int n, m;

void right(int x, int y) {
	for (int s = y + 1; s < m; s++) {
		if (arr[x][s] == 6) return;
		else check[x][s] = -1;
	}
}
void left(int x, int y) {
	for (int s = y - 1; s >= 0; s--) {
		if (arr[x][s] == 6) return;
		else check[x][s] = -1;
	}
}
void up(int x, int y) {
	for (int s = x - 1; s >= 0; s--) {
		if (arr[s][y] == 6) return;
		else check[s][y] = -1;
	}
}
void down(int x, int y) {
	for (int s = x + 1; s < n; s++) {
		if (arr[s][y] == 6) return;
		else check[s][y] = -1;
	}
}
vector<tuple<int,int,int>>s;
int ans = 64;
int dir[10];

void cctv1(int c, int i, int j)
{
	if (c == 1) up(i, j);
	else if (c == 2) left(i, j);
	else if (c == 3) down(i, j);
	else if(c == 4)	right(i, j);
}

void cctv2(int c, int i, int j)
{
	if (c == 1) {
		up(i, j), down(i, j);
	}
	else if (c == 2) {
		right(i, j), left(i, j);
	}
	else if (c == 3) {
		up(i, j), down(i, j);
	}
	else if (c == 4) {
		right(i, j), left(i, j);
	}

}
void cctv3(int c, int i, int j)
{
	if (c == 1) {
		up(i, j), right(i, j);
	}
	else if (c == 2) {
		up(i, j), left(i, j);
	}
	else if (c == 3) {
		down(i, j), left(i, j);
	}
	else if (c == 4) {
		down(i, j), right(i, j);
	}

}
void cctv4(int c, int i,int j)
{
	if (c == 1) {
		up(i, j), right(i, j), left(i, j);
	}
	else if (c == 2) {
		up(i, j), left(i, j), down(i, j);
	}
	else if (c == 3) {
		down(i, j), right(i, j), left(i, j);
	}
	else if (c == 4) {
		down(i, j), right(i, j), up(i, j);
	}
}

void go(int select)
{
	//n개의 cctv 에 대한 방향 중복 순열
	if (select == s.size()) {
		for (int c = 0; c < select; c++) {
			int num; int i; int j;
			tie(num, i, j) = s[c];
			if (num == 1) cctv1(dir[c], i, j);
			if (num == 2) cctv2(dir[c], i, j);
			if (num == 3) cctv3(dir[c], i, j);
			if (num == 4) cctv4(dir[c], i, j);
		}
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (check[i][j] == 0) tmp++;
			}
		}
		ans = min(tmp, ans);

		//원래로 초기화
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) check[i][j] = -1;
				else check[i][j] = 0;
			}
		}

		//cctv 5번
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 5) {
					right(i, j); left(i, j);
					up(i, j); down(i, j);
				}
			}
		}

		return;
	}

	for (int i = 1; i <= 4; i++) {
		//방향
		dir[select] = i;
		go(select + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) check[i][j] = -1;
			if (arr[i][j] != 5 && arr[i][j] != 6 && arr[i][j] != 0) {
				s.push_back({ arr[i][j],i,j });
			}
		}
	}

	//cctv 5번
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 5) {
				//오른쪽
				right(i, j);
				//왼쪽
				left(i, j);
				//위
				up(i, j);
				//아래
				down(i, j);
			}
		}
	}
	go(0);

	cout << ans;
	return 0;
}