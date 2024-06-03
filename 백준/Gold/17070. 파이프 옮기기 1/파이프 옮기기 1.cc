#include<iostream>
using namespace std;

int n, arr[20][20], dp[20][20][3];
//dp는 (a,b)로 올수있는 파이프의 수, 0:가로 / 1:세로 / 2:대각

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++) 
        for(int j = 1; j<=n; j++) cin >> arr[i][j];
    
    dp[1][2][0] = 1;
    for(int i = 3; i<=n; i++) {
        if(!arr[1][i]) dp[1][i][0] = dp[1][i-1][0];
    }
    
    for(int i = 2; i<=n; i++) {
        for(int j = 2; j<=n; j++) {
            if(!arr[i][j]){
                dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
                dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
                
            }
            if(!arr[i][j] && !arr[i-1][j] && !arr[i][j-1]){
                dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
            }
        }
    }
    
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
     
    return 0;
}