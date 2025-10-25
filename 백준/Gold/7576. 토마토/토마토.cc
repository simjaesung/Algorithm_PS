#include <iostream>
#include <queue>
using namespace std;
int n,m,ans;
int arr[1005][1005];
int visited[1005][1005];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool inRange(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}
void input(){
	cin >> m >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cin >> arr[i][j];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	queue<pair<int,int>> q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(arr[i][j] == 1) {
				q.push({i,j});
				visited[i][j] = 1;
			}
		}
	}

	while(!q.empty()){
		auto[cx,cy] = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(!inRange(nx, ny)) continue;
			if(arr[nx][ny] == -1) continue;
			if(visited[nx][ny]) continue;
			visited[nx][ny] = visited[cx][cy] + 1;
			q.push({nx,ny});
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(visited[i][j] == 0 && arr[i][j] == 0){
				cout << -1;
				return 0;
			}
			if(visited[i][j]){
				ans = max(ans, visited[i][j] - 1);
			}
		}
	}
	cout << ans;
	return 0;
}