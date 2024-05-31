#include<iostream>
#include<algorithm>
using namespace std;

int n,m,k,r,c,ans,tmp;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int arr[105][105], visit[105][105];

bool inrange(int x, int y){
    return x >= 1 && x <=n && y >= 1 && y <= m;
} 

void dfs(int x, int y){
    visit[x][y] = 1;
    tmp++;
    for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!inrange(nx,ny)) continue;
        if(arr[nx][ny] && !visit[nx][ny]) dfs(nx,ny);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    while(k--){
        cin >> r >> c;
        arr[r][c] = 1;
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            tmp = 0;
            if(arr[i][j]){
                for(int i = 1; i<=100; i++) fill(visit[i],visit[i]+105,0);
                dfs(i,j);
                ans = max(ans,tmp);
            }
        }
    }
    
    cout << ans;
    
    return 0;
}