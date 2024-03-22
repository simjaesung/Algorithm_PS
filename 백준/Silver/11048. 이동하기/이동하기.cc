#include<iostream>
#include<queue>
using namespace std;
int n,m,ans;
int arr[1005][1005], dp[1005][1005];
int dx[] = {1,0,1};
int dy[] = {1,1,0};

bool inrange(int x, int y){
    return x >=1 && x <= n && y >= 1 && y <= m;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j ++) 
            cin >> arr[i][j];
    }
    dp[1][1] = arr[1][1];
    
    for(int i = 1; i <= n; i++ ){
        for(int j = 1; j <= m; j++ ){
            for(int k = 0; k<3; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(inrange(nx, ny))
                    dp[nx][ny] = max(dp[nx][ny], dp[i][j] + arr[nx][ny]);
            }
        }
    }
    
    
    cout << dp[n][m];
    
    return 0;
}