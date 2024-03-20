#include<iostream>
#include<tuple>
#include<queue>
using namespace std;

int m, n, h;
int box[105][105][105];
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

int inrange(int x, int y, int z) 
{
	if (x >= 0 && x < n && y >= 0 && y < m && z >= 0 && z < h)
		return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n >> h;
	queue<tuple<int, int, int>>q;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> box[i][j][k];
				if(box[i][j][k] == 1) q.push(make_tuple(i, j, k));
			}
		}
	}

	while (!q.empty()) {
		int cz = get<0>(q.front());
		int cx = get<1>(q.front());
		int cy = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = cz + dz[i];
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (inrange(nx, ny, nz)) {
				if (box[nz][nx][ny] == 0) {
					box[nz][nx][ny] = box[cz][cx][cy] + 1;
					q.push(make_tuple(nz, nx, ny));
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (box[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				ans = max(ans, box[i][j][k]);
			}
		}
	}

	cout << ans - 1;
	
	
	return 0;
}