#include<iostream>
using namespace std;
long long n,k,dp[1005][1005];

int com(int a, int b){
    for(int i = 1; i <= a; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }
    
    return dp[a][b] % 10007;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    cout << com(n,k);
    return 0;
}