#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n,m,a,b,ans;
vector<int> v[505];
int c[505];

void bfs(int x){
    queue<pair<int,int>>q;
    q.push({x,0});
    while(!q.empty()){
        int cx = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(c[cx] || cnt > 2) continue;
        
        c[cx] = 1;
        ans++;
        
        for(auto nx : v[cx]){
            if(!c[nx]) q.push({nx,cnt + 1});
        }   
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    bfs(1);
    cout << ans - 1; //상근 제외
    
    return 0;
}