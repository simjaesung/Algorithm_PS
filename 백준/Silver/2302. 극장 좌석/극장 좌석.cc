#include<iostream>
#include<vector>
using namespace std;
vector<int>v;
int dp[45];
int n,m,f,ans = 1;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++) {
        cin >> f; v.push_back(f);
    }
    
    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    for(int i = 3; i<=40; i++) dp[i] = dp[i-2] + dp[i-1];
    
    if(m == 0){
        cout << dp[n]; 
        return 0;
    }
    
    vector<int>inter;
    inter.push_back(v[0]-1);
    inter.push_back(n-v[m-1]);
    for(int i = 0; i<m-1; i++) inter.push_back(v[i+1] - v[i] - 1);
    for(auto x : inter) ans *= dp[x];
    cout << ans;
    return 0;
}