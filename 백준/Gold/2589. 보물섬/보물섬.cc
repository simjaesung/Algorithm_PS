#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
int n,m,ans,tmp;
int arr[55][55],visit[55][55];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
bool inrange(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

void bfs(int x, int y){
    queue<tuple<int,int,int>>q;
    q.push({x,y,0});
    visit[x][y] = 1;
    while(!q.empty()){
        int cx,cy,cnt;
        tie(cx,cy,cnt) = q.front();
        tmp = max(cnt,tmp);
        q.pop();
        for(int i = 0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(!inrange(nx,ny) || visit[nx][ny] || !arr[nx][ny]) continue;
            visit[nx][ny] = 1;
            q.push({nx,ny,cnt+1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i <n; i++){
        string s; cin >> s;
        for(int j = 0; j<m; j++) if(s[j] == 'L') arr[i][j] = 1;
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            tmp = 0;
            if(arr[i][j]) {
                for(int i = 0; i<n; i++) fill(visit[i],visit[i]+m,0);
                bfs(i,j);
                ans = max(ans,tmp);
            }
        }
    }
    cout << ans;
    return 0;
}