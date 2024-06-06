#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//당신의 병사들은 흰색 옷을 입고, 적국의 병사들은 파란색 옷
int n,m,w,b,f;
int arr[105][105], visit[105][105];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool inrange(int x,int y){
    return x>=0 && x < m && y>=0 && y<n;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);    
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        string s; cin >> s;
        for(int j = 0; j<n; j++) if(s[j] == 'W') arr[i][j] = 1;
    }
    
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            f = arr[i][j];
            int cnt = 0;
            queue<pair<int,int>>q;
            q.push({i,j});
            while(!q.empty()){
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                if(visit[cx][cy]) continue;
                cnt++;
                visit[cx][cy] = 1;
                for(int i = 0; i<4; i++){
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    if(!inrange(nx,ny) || arr[nx][ny] != f) continue;
                    q.push({nx,ny});
                }
            }
            if(f == 1) w += cnt * cnt;
            else b += cnt * cnt; 
        }
    }
    cout << w << ' ' << b;    
    return 0;
}