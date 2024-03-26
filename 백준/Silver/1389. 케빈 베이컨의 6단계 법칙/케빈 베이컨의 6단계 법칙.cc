#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
using namespace std;

int n,m,a,b;
vector<vector<int>>v(105);
int c[105];
int val = INT_MAX, ans;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++){
        fill(c,c+n+1,0);
        
        int cnt = 0;
        queue<pair<int,int>>q;
        q.push({i,0});
        c[i] = 1;
        
        while(!q.empty()){
            int cx = q.front().first;
            int s = q.front().second;
            q.pop();
            for(auto x : v[cx]){
                if(!c[x]) {
                    c[x] = 1;
                    q.push({x,s + 1});
                    cnt += s + 1;
                }
            }
        }
        if(cnt < val) {
            ans = i;
            val = cnt;
        }
    }
    cout << ans;
    return 0;
}