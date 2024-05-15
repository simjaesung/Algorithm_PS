#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a,b,c,ans,p[1005];
vector<tuple<int,int,int>>adj;

int find(int r){
    if(p[r] == r) return r;
    return p[r] = find(p[r]);
}

void merge(int a, int b){
    a = find(a); b = find(b);
    if(a >= b) p[a] = b;
    else p[b] = a;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i<=n; i++) p[i] = i;
    
    while(m--){
        cin >> a >> b >> c;
        adj.push_back({c,a,b});
    }
    
    sort(adj.begin(),adj.end());
    int cnt = 0;
    for(auto x : adj){
        tie(a,b,c) = x;
        if(find(b) == find(c)) continue;
        merge(b,c);
        ans += a;
        cnt++;
        if(cnt == n-1) break;
    }
    cout << ans;
    return 0;
}