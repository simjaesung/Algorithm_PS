#include <iostream>
#include <vector>
#include <queue>
using namespace std;
char arr[5][5]; 
int ans;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
vector<pair<int,int>> selected;

bool inRange(int x, int y){
	return x >= 0 && x < 5 && y >=0 && y < 5;
}

bool isConnected(){
	queue<pair<int,int>> q;
	bool visited[5][5] = {0};
	visited[selected[0].first][selected[0].second] = true;
	q.push(selected[0]);

	int cnt = 1;
	while(!q.empty()){
		auto[cx, cy] = q.front(); q.pop();
		for(int k = 0; k < 4; k++){
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if(!inRange(nx,ny)) continue;
			for(auto[sx, sy] : selected){
				if(sx == nx && sy == ny && !visited[sx][sy]){
					visited[sx][sy] = true;
					q.push({sx,sy});
					cnt++;
				}
			}
		}
	}
	return cnt == 7;
}

void input(){
	string s;
	for(int i = 0; i < 5; i++){
		cin >> s;
		for(int j = 0; j < 5; j++) arr[i][j] = s[j];
	}
}

void go(int k, int S, int idx){
	if(k == 7){
		if(S >= 4 && isConnected()) ans++;
		return;
	}

	for(int i = idx; i < 25; i++){
		int x = i / 5; int y = i % 5;
		selected.push_back({x,y});
		go(k + 1, S + (arr[x][y] == 'S'), i + 1);
		selected.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	go(0,0,0);
	cout << ans;
	return 0;
}