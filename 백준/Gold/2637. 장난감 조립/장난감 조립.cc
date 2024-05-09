#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<pair<int,int>>adj[105];
queue<int>q;
int ans[105], taken[105];
int n,m,x,y,k;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> x >> y >> k;
        adj[x].push_back({y,k});
        taken[y]++;
    }
    q.push(n);
    ans[n] = 1;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(auto s : adj[tmp]){
            ans[s.first] += ans[tmp] * s.second;
            if(--taken[s.first] == 0) q.push(s.first);
        }
    }
    for(int i = 1; i<=n; i++) {
        if(adj[i].empty()) cout << i << ' ' << ans[i] << '\n';
    }
    return 0;
}
