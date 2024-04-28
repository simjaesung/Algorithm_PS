#include<iostream>
#include<vector>
using namespace std;
int ans[100005];
vector<int>c[100005];
int n,m,val,k;

void sol(int r, int parent)
{
    if(r != 1) ans[r] += ans[parent];
    for(int i = 0; i<c[r].size();i++) sol(c[r][i],r);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> val;
        if(val != -1) c[val].push_back(i);
    }
    for(int i = 0; i<m; i++){
        cin >> val >> k;
        ans[val] += k;
    }
    
    sol(1,-1);
    for(int i = 1; i <= n; i++) cout << ans[i] <<' ';
    return 0;
}