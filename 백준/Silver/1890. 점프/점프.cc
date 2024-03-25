#include<iostream>
#include<queue>
using namespace std;

int n, arr[105][105], tmp1[2], tmp2[2];
long long dp[105][105];

bool inrange(int x,int y){
    return x >= 0 && x < n && y >=0 && y < n;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) cin >> arr[i][j];
    }
    
    dp[0][0] = 1;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) {
            if(!dp[i][j]) continue;
            if(i == n-1 && j == n-1) continue;
            tmp1[0] = arr[i][j];
            tmp2[1] = arr[i][j];
            
            for(int k = 0; k < 2; k++){
                int nx = i + tmp1[k];
                int ny = j + tmp2[k];
                if(inrange(nx,ny)) dp[nx][ny] += dp[i][j];
            }
        }
    }
    
    cout << dp[n-1][n-1];
    return 0;
}