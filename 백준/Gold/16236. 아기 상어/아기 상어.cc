#include<iostream>
#include<algorithm>
#include<queue>
#include<limits.h>
using namespace std;
int n;
int sx, sy, ssize = 2; //아기상어 위치와 무게
int arr[25][25], c[25][25];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

bool inrange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push(make_pair(x, y)); c[x][y] = 0;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!inrange(nx, ny)) continue;

			//물고기의 크기가 클 경우
			if (arr[nx][ny] > ssize) continue;

			//이미 방문했을 경우
			if (c[nx][ny] != -1) continue;
			c[nx][ny] = c[cx][cy] + 1;
			q.push(make_pair(nx, ny));
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				//처음 아기상어의 위치
				sx = i, sy = j;
			}
		}
	}

	int eat = 0, ans = 0;
	while (1) {
		for (int i = 0; i < n; i++) fill(c[i], c[i] + n, -1);

		//다닐 수 있는 공간 탐색
		bfs(sx, sy);

		int dist = INT_MAX;

		//상어의 다음 위치
		int nsx = sx, nsy = sy;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// 먹이감 찾기
				// 빈칸이 아니면서 사이즈가 작을 경우 먹을 수 있음 갈수있는 곳이면
				// 사이즈가 9일때 같아짐을 조심
				if (arr[i][j] != 0 && arr[i][j] < ssize && c[i][j] != -1) {
					if (arr[i][j] != 9 && dist > c[i][j]) {
						dist = c[i][j];
						nsx = i, nsy = j;
					}
				}
			}
		}
		//위치가 이전 위치와 같을 경우 먹을 물고기가 없는 것
		if (nsx == sx && nsy == sy) break;
		else {
			arr[nsx][nsy] = 0;
			swap(arr[sx][sy], arr[nsx][nsy]);
			sx = nsx; sy = nsy;
			
			eat++;
			if (eat == ssize) {
				ssize++;
				eat = 0;
			}
			ans+= dist;
		}
	}
	cout << ans;
	
	return 0;
}