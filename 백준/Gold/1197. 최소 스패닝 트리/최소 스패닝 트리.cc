#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
using namespace std;

priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq;
int c[10005]; //정점 체크
vector<pair<int,int>>adj[10005]; //연결된 간선, 가중치
int v,e,cost,a,b,ans,cnt;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> v >> e;
    for(int i = 0; i<e; i++){
        cin >> a >> b >> cost;
        adj[a].push_back({b,cost});
        adj[b].push_back({a,cost});
    }
    
    for(auto x : adj[1]){
        pq.push({x.second, 1, x.first});
    }
    
    c[1] = 1;
    while(cnt < v-1){
        int cost;
        tie(cost,a,b) = pq.top(); pq.pop();
        if(c[b]) continue;
        ans += cost;
        cnt++;
        c[b] = 1;
        for(auto x : adj[b]){
            if(!c[x.first]) pq.push({x.second,b,x.first});
        }
    }
    
    cout << ans;
    return 0;
}