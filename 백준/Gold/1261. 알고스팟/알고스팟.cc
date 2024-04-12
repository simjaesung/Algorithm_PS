#include<iostream>
#include<deque>
#include<limits.h>
using namespace std;
int n,m;
int arr[105][105], c[105][105];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool inrange(int x, int y){
    return x >=1 && x <= n && y >= 1 && y <=m;
}

int main()
{
    cin >> m >> n;
    
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        for(int j = 1; j <= m; j++) {
            arr[i][j] = s[j-1] - '0';
        }
    }
    c[n][m] = INT_MAX;
    
    deque<pair<pair<int,int>,int>>dq;
    dq.push_front({{1,1},0});
    
    while(!dq.empty()){
        int cx = dq.front().first.first;
        int cy = dq.front().first.second;
        int cnt = dq.front().second;
        dq.pop_front();
        
        if(cx == n && cy == m) {
            c[n][m] = min(c[n][m],cnt);
            continue;
        }
        if(c[cx][cy]) continue;
        c[cx][cy] = 1;
        
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(!inrange(nx,ny)) continue;
            if(arr[nx][ny]) dq.push_back({{nx,ny},cnt + 1});    
            else dq.push_front({{nx,ny},cnt});
        }
    }
    
    cout << c[n][m];
    
    return 0;
}