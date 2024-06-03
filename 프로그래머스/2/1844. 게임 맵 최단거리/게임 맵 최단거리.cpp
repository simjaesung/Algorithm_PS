#include<vector>
#include<queue>
#include<tuple>
using namespace std;
int n,m;
int answer = -1,arr[105][105], v[105][105],ans[105][105];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool inrange(int x, int y){
    return x>0 && x<=n && y>0 && y<=m;
}

int solution(vector<vector<int>> maps)
{
    n = maps.size();
    m = maps[0].size();
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++) arr[i+1][j+1] = maps[i][j];
    }
    
    queue<tuple<int,int,int>>q;
    q.push({1,1,1}); v[1][1] = 1;
    while(!q.empty()){
        int cx,cy,cnt;
        tie(cx,cy,cnt) = q.front();
        q.pop();
        if(cx == n && cy == m) {
            answer = cnt;
            break;
        }
        for(int i = 0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(!inrange(nx,ny) || !arr[nx][ny] || v[nx][ny]) continue;
            v[nx][ny] = 1;
            q.push({nx,ny,cnt+1});
        }
    }
    
    return answer;
}