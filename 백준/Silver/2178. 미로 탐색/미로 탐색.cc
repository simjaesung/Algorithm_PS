#include <iostream>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

int n,m,ans = INT_MAX;
int arr[105][105];
bool visited[105][105];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool inRange(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void input(){
	cin >> n >> m;
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		for(int j = 0; j < m; j++) arr[i][j] = s[j] - '0';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	input();
	queue<tuple<int,int,int>> q;
	q.push({0,0,1});
	visited[0][0] = 1;
	while(!q.empty()){
		auto[cx,cy,cnt] = q.front(); q.pop();
		if(cx == n - 1 && cy == m - 1) {
			ans = min(ans, cnt);
			continue;
		}
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
 			if(!inRange(nx,ny) || visited[nx][ny] || !arr[nx][ny]) continue;
			visited[nx][ny] = 1;
			q.push({nx,ny,cnt+1});
		}
	}
	
	cout << ans;
	return 0;
}