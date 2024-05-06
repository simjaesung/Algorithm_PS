#include<iostream>
#include<queue>
#include<vector>
using namespace std;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
vector<pair<int,int>>adj[100005];
int c[100005];
int n,m,a,b,cost,cnt,ans,tmp;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> a >> b >> cost;
        adj[a].push_back({b,cost});
        adj[b].push_back({a,cost});
    }
    
    c[1] = 1;
    for(auto x : adj[1]) pq.push({x.second, x.first});
    
    while(cnt < n-1){
        cost = pq.top().first;
        a = pq.top().second;
        pq.pop();
        if(c[a]) continue;
        c[a] = 1;
        ans += cost;
        tmp = max(tmp,cost);
        cnt++;
        for(auto x : adj[a]){
            if(!c[x.first]) pq.push({x.second, x.first});
        }
    }
    cout << ans-tmp;
    return 0;
}