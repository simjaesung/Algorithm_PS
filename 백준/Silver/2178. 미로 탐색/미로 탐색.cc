#include <iostream>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

int n,m,ans = INT_MAX;
int arr[105][105];
int dist[105][105];
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

	for(int i = 0; i < n; i++){
		fill(dist[i], dist[i] + m, -1);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	input();
	queue<pair<int,int>> q;
	q.push({0,0});
	dist[0][0] = 1;
	while(!q.empty()){
		auto[cx,cy] = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
 			if(!inRange(nx,ny) || dist[nx][ny] != -1 || !arr[nx][ny]) continue;
			dist[nx][ny] = dist[cx][cy] + 1;
			q.push({nx,ny});
		}
	}
	
	cout << dist[n-1][m-1];
	return 0;
}