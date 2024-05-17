#include<iostream>
using namespace std;
int r,c,ans;
string s;
bool inrange(int x, int y){
    return x >=1 && x <=r && y >=1 && y <= c;
}
int check[30];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
char arr[22][22];
int visit[22][22];

void go(int x, int y){
    int tmp = 0;
    for(int i = 0; i<30; i++){
        if(check[i]) tmp++;
    }
    ans = max(ans, tmp);
    
    for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nxt = arr[nx][ny] - 'A';//다음 알파벳
        if(!inrange(nx,ny) || check[nxt] || visit[nx][ny]) continue;
        check[nxt] = 1;
        visit[nx][ny] = 1;
        go(nx,ny);
        check[nxt] = 0;
        visit[nx][ny] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> r >> c;
    for(int i = 1; i<=r; i++){
        cin >> s;
        for(int j = 1; j<=c; j++) arr[i][j] = s[j-1];
    }
    visit[1][1] = 1;
    check[arr[1][1]-'A'] = 1;
    go(1,1);
    cout << ans;
    return 0;
}