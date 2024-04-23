#include<iostream>
#include<vector>
using namespace std;
int siz[100005];
vector<int>g[100005];
int n,r,q,u,v;

void countSub(int r, int par){
    siz[r] = 1;
    for(auto child : g[r]){
        if(child == par) continue;
        countSub(child,r);
        siz[r] += siz[child];
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> r >> q;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    countSub(r, 0);
    
    while(q--){
        cin >> u;
        cout << siz[u] <<'\n';
    }
    
    return 0;
}