#include<iostream>
using namespace std;

int arr[55][55];
int n, m;
int x, y, dir;

//북동남서
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int ans = 0;

bool inrange(int a, int b) {
	return a >= 0 && a < n && b >= 0 && b < m;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	cin >> x >> y >> dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> arr[i][j];
	}
	
	while (1) {
		//벽일 경우
		if (arr[x][y] == 1) break;

		if (arr[x][y] == 0) {
			ans++;
			//청소 표시
			arr[x][y] = -1;
		}

		int check = 0;
		//청소할 구역이 있는지 확인
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (inrange(nx, ny) && arr[nx][ny] == 0) check = 1;
		}

		if (check) {
			for (int i = 1; i <= 4; i++) {
				//반시계
				int f = (dir - i + 4) % 4;
				if (arr[x + dx[f]][y + dy[f]] == 0) {
					dir = f;
					x = x + dx[f];
					y = y + dy[f];
					break;
				}
			}
		}
		else {
			//후진
			// dir : 0(북쪽), x + 1 (남쪽으로)
			// dir : 1(동쪽), y - 1 (서쪽으로)
			// dir : 2(남쪽), x - 1 (북쪽으로)
			// dir : 3(서쪽), y + 1 (동쪽으로)
			if (dir == 0) x += 1;
			else if (dir == 1) y -= 1;
			else if (dir == 2) x -= 1;
			else if (dir == 3) y += 1;
		}
	}

	cout << ans;
	
	return 0;
}