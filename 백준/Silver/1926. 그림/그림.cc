#include <iostream>
#include <queue>
using namespace std;

int n,m;
int ans1,ans2;
int arr[505][505];
bool visited[505][505];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool inRange(int x, int y){
	return x >= 0 && x < n && y >=0 && y < m;
}

void input(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cin >> arr[i][j];
	}
}

void bfs(int x, int y){
	queue<pair<int,int>> q;
	q.push({x,y});
	visited[x][y] = 1;
	int width = 1;
	while(!q.empty()){
		auto [cx,cy] = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(!inRange(nx,ny) || arr[nx][ny] == 0 || visited[nx][ny]) continue;
			visited[nx][ny] = 1;
			width++;
			q.push({nx,ny});
		}
	}
	ans2 = max(ans2, width);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(visited[i][j] || arr[i][j] == 0) continue;
			ans1++;
			bfs(i,j);
		}
	}
	cout << ans1 << "\n" << ans2;
}