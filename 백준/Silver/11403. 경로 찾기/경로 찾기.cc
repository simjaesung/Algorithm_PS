#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int n,val;
vector<vector<int>>v(105);
int c[105];

int bfs(int s, int e){
    queue<pair<int,int>>q;
    q.push({s,0});
    
    while(!q.empty()){
        int cx = q.front().first;
        int dep = q.front().second;
        q.pop(); c[cx] = 1;
        if(dep > 0 && cx == e) return 1;
        
        for(auto x : v[cx]){
            if(dep > 0 && x == e) return 1;
            if(!c[x]) q.push({x,dep + 1});
        }
    }
    
    return 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> val;
            if(val == 1) v[i].push_back(j);
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int s = 1; s <= 100; s++) c[s] = 0;
            if(bfs(i,j)) cout << 1 << ' ';
            else cout << 0 << ' ';
        }
        cout << '\n';
    }
    return 0;
}