#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int,int>>adj[1005];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
int visit[1005];
int n,m,k,u,v,w,cnt,ans;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    while(k--){
        int val; cin >> val;
        visit[val] = 1; cnt++;
    }
    while(m--){
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i = 1; i<=n; i++){
        if(visit[i]){
            for(auto x : adj[i]) pq.push({x.second, x.first});
        }
    }
    
    while(cnt < n){
        int cost = pq.top().first;
        int nxt = pq.top().second;
        pq.pop();
        if(visit[nxt]) continue;
        visit[nxt] = 1;
        ans += cost;
        cnt++;
        for(auto x : adj[nxt]){
            if(!visit[x.first]) pq.push({x.second,x.first});
        }
    }
    cout << ans;
    
}