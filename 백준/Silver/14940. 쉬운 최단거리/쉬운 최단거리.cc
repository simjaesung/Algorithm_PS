#include<iostream>
#include<queue>
using namespace std;
int arr[1005][1005],c[1005][1005],visit[1005][1005];
int n,m;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool inrange(int x, int y){
    return x >=0 && x < n && y >=0 && y < m;
}
queue<pair<int,int>>q;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) q.push({i,j});
        }
    }
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        if(visit[cx][cy]) continue;
        visit[cx][cy] = 1;
        for(int i = 0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(!inrange(nx,ny) || !arr[nx][ny] || visit[nx][ny]) continue;
            c[nx][ny] = c[cx][cy] + 1;
            q.push({nx,ny});
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++) {
            if(arr[i][j]==1 && !c[i][j]) cout << -1 << ' ';
            else cout << c[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}