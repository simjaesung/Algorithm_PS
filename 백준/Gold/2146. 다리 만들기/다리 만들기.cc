#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int arr[105][105], c[105][105], b[105][105];
int n;

bool inrange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(int x, int y, int cnt)
{
	c[x][y] = cnt;
	queue<pair<int,int>>q; 
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (inrange(nx, ny)) {
				if (arr[nx][ny] == 1 && c[nx][ny] == 0) {
					c[nx][ny] = cnt;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int bfs2(int x, int y, int land)
{
	b[x][y] = 1;
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (inrange(nx, ny) && b[nx][ny] == 0) {
				//육지일 경우
				
				if (arr[nx][ny] == 1) {
					//육지인데 다른 대륙이면(다리완성)
					if (c[nx][ny] != land) {
						return b[cx][cy];
					}
				}
				//바다일 경우
				else {
					b[nx][ny] = b[cx][cy] + 1;
					q.push(make_pair(nx, ny));
				}
				
			}
		}
	}
	return -1;
}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}

	//대륙 별 번호 메겨주기 
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && c[i][j] == 0)
				bfs(i, j, ++cnt);
		}
	}

	int ans = 200;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) { 
				//바다이고 사방에 육지가 있으면
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (inrange(nx, ny) && arr[nx][ny] == 1) {
						//갈수있는 짧은 다리길이 찾기
						int val = bfs2(i, j, c[nx][ny]);
						if (val != -1)ans = min(ans, val);
						

						//다리 제작도 초기화
						for (int s = 0; s < 105; s++)
							fill(b[s], b[s] + 105, 0);
					}
				}
			}
		}

	}
	cout << ans;
		
	
	return 0;
}