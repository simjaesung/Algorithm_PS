#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int arr[105][105];
int visit[105][105];
int n,m,cnt,ans; //cnt는 치즈개수
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool inrange(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
            if(arr[i][j]) cnt++;
        }
    }
    
    while(cnt > 0){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++) {
                visit[i][j] = 0;
                if(arr[i][j] == 2) arr[i][j] = 0;
            }
        }
            
        //내부에 있는 공기 찾기
        vector<pair<int,int>>inAir;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(arr[i][j] == 0 && !visit[i][j]){
                    vector<pair<int,int>>tmp;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    visit[i][j] = 1;
                    int check = 1;
                    while(!q.empty()){
                        int cx = q.front().first;
                        int cy = q.front().second;
                        q.pop();
                        tmp.push_back({cx,cy});
                        for(int k = 0; k<4; k++){
                            int nx = cx + dx[k];
                            int ny = cy + dy[k];
                            if(visit[nx][ny] || arr[nx][ny] != 0) continue;
                            if(!inrange(nx,ny)){
                                check = 0;
                                continue;
                            }
                            visit[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                    if(check){
                        for(auto x : tmp) inAir.push_back({x.first,x.second});
                    }
                }
            }
        }
        for(auto x : inAir) arr[x.first][x.second] = 2;
        
        vector<pair<int,int>>melt;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(arr[i][j] == 1){
                    int air = 0;
                    for(int k = 0; k<4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(!inrange(nx,ny)) continue;
                        if(arr[nx][ny] == 0) air++;
                    }
                    if(air >= 2) melt.push_back({i,j});
                }
            }
        }
        for(auto x : melt) {
            arr[x.first][x.second] = 0;
            cnt--;
        }
        
        ans++;
    }
    cout << ans;
    return 0;
}