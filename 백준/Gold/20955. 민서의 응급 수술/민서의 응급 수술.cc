#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>v[100005];
int visit[100005];
int n,m,a,b,group;

void dfs(int r)
{
    visit[r] = 1;
    for(auto x : v[r]){
        if(!visit[x]) dfs(x);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i = 1; i<=n; i++){
        if(!visit[i]){
            group++;
            dfs(i);
        }
    }
    cout << group-1 + (m+group-1)-(n-1);
    
    return 0;
}