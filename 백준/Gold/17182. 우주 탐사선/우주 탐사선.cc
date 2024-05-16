#include<iostream>
using namespace std;

int r[12][12],visit[12];
int n,k,val,ans = 0x7f7f7f7f;

//방문개수, 현재위치, 전체시간
void go(int cnt, int now, int time){
    if(cnt == n){
        ans = min(ans,time);
        return;
    }
    
    for(int i = 0; i<n; i++){
        if(visit[i]) continue;
        visit[i] = 1;
        go(cnt + 1, i, time + r[now][i]);
        visit[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) cin >> r[i][j];
    }
    
    for(int s = 0; s<n; s++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++) {
                r[i][j] = min(r[i][j], r[i][s] + r[s][j]);
            }
        }
    }
    visit[k] = 1; //출발지점 방문처리
    go(1,k,0);
    cout << ans;
    return 0;
}