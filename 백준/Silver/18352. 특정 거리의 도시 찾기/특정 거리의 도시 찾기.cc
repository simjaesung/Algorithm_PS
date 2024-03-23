#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m,k,x,s,e; //s:출발 e:도착

vector<int>v[300005];
int c[300005];
vector<int>ans;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k >> x;
    
    for(int i = 0; i < m; i++){
        cin >> s >> e;
        v[s].push_back(e);
    }
    
    queue<pair<int,int>>q;
    q.push({x,0});
    c[x] = 1;
    
    while(!q.empty()){
        int cx = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(cnt == k) {
            ans.push_back(cx);
            continue;
        }
        
        for(auto tmp : v[cx]){
            if(!c[tmp]) {
                q.push({tmp,cnt + 1});
                c[tmp] = 1;
            }
        }
    }
    
    if(ans.empty()){
        cout << -1;
        return 0;
    }
    
    sort(ans.begin(),ans.end());
    for(auto x: ans) cout << x << '\n';
    
    return 0;
}