#include<iostream>
#include<vector>
using namespace std;
int n,a,b,k,ans = -1;
vector<int>v[105];
int c[105];

void dfs(int x,int depth){
    c[x] = 1;
    if(x == b) {
        ans = depth;
        return;
    }
    
    for(int i = 0; i < v[x].size(); i++){
        int next = v[x][i];
        if(!c[next]) dfs(next, depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> a >> b >> k;
    for(int i = 0; i < k; i++){
        int p1,p2;
        cin >> p1 >> p2;
        v[p1].push_back(p2);
        v[p2].push_back(p1);
    }
    dfs(a,0);
    cout << ans;
    
    return 0;
}