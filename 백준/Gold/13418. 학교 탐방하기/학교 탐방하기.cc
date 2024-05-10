#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int visit1[1005],visit2[1005];
vector<pair<int,int>>adj[1005];
int n,m,a,b,c,ans1,ans2;
priority_queue<pair<int,int>>pq1; //최대
priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq2; //최소

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    m++;
    while(m--){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    //최선의 경로
    visit1[0] = 1;
    for(auto x : adj[0]) pq1.push({x.second,x.first});
    int cnt1 = 0;
    while(cnt1 < n){
        a = pq1.top().first;//오르?내리?
        b = pq1.top().second;//다음위치
        pq1.pop();
        if(visit1[b]) continue;
        if(a == 0) ans1++;
        cnt1++;
        visit1[b] = 1;
        for(auto x : adj[b]){
            if(!visit1[x.first]) pq1.push({x.second,x.first});
        }
    }
    
    //최악의 경로
    visit2[0] = 1;
    for(auto x : adj[0]) pq2.push({x.second,x.first});
    int cnt2 = 0;
    while(cnt2 < n){
        a = pq2.top().first;
        b = pq2.top().second;
        pq2.pop();
        if(visit2[b]) continue;
        if(a == 0) ans2++;
        cnt2++;
        visit2[b] = 1;
        for(auto x : adj[b]){
            if(!visit2[x.first]) pq2.push({x.second,x.first});
        }
    }
    cout << (ans2*ans2) - (ans1*ans1);
    return 0;
}