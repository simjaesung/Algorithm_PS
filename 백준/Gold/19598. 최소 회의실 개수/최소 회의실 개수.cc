#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
priority_queue<int,vector<int>,greater<int>>pq;
int n,s,e,ans;
vector<pair<int,int>>v;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s >> e;
        v.push_back({s,e});
    }
    sort(v.begin(), v.end());
    
    for(int i = 0; i < n; i++){
        if(pq.empty() || pq.top() > v[i].first){
            ans++;
            pq.push(v[i].second);
        }
        else{
            pq.pop();
            pq.push(v[i].second);
        }
    }
    cout << ans;
    return 0;
}