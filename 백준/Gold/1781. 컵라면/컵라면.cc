#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>>pq;
vector<pair<int,int>>v;

int n,a,b;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    
    sort(v.begin(),v.end());
    
    for(int i = 0; i < n; i++){
        int dead = v[i].first;
        int ramen = v[i].second;
        pq.push(ramen);
        if(pq.size() > dead) pq.pop();
    }
    
    int ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
    
    return 0;
}