#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>>v[10005];
int visit[10005];
int n,a,b,c,p,tmp;

void dfs(int r,int val){
    visit[r] = 1;
    if(val > tmp) {
        p = r;
        tmp = val;
    }
    
    if(v[r].empty()) return;
    for(auto x : v[r]){
        if(!visit[x.first]) dfs(x.first, val + x.second);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    
    dfs(1,0);
    tmp = 0;
    fill(visit, visit+10005,0);
    dfs(p,0);
    cout << tmp;
}