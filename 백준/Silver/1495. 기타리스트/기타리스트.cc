#include<iostream>
using namespace std;
int n,s,m,answer = -1;
int song[55], dp[55][1005];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s >> m;
    for(int i = 1; i<=n; i++) cin >> song[i];
    dp[0][s] = 1;
    for(int i = 1; i<=n; i++){
        for(int k = 0; k <=m; k++){
            if(dp[i-1][k] && k + song[i] <= m) dp[i][k + song[i]] = 1;
            if(dp[i-1][k] && k - song[i] >= 0) dp[i][k - song[i]] = 1;
        }
    }
    for(int i = 0; i<=m; i++){
        if(dp[n][i]) answer = max(answer,i);
    }
    cout << answer;
    return 0;
}