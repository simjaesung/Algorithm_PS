#include<iostream>
#include<vector>
using namespace std;
vector<int> v[100005];
int ans[100005];
int n,a,b;

void dfs(int x){
    for(auto k : v[x]){
        if(!ans[k]){
            ans[k] = x;
            dfs(k);   
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    
    for(int i = 2; i<=n; i++){
        cout << ans[i] << '\n';
    }
    
    return 0;
}