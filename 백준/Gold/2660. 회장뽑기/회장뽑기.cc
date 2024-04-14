#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n,a,b;
vector<vector<int>>v(55);
int c[55],ans[55];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(1){
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++){
        fill(c,c+n+1,0);
        queue<pair<int,int>>q;
        q.push({i,0});
        
        while(!q.empty()){
            int cx = q.front().first;
            int s = q.front().second;
            q.pop();
            if(c[cx]) continue;
            ans[i] = max(ans[i],s);
            c[cx] = 1;
            
            for(auto f : v[cx]){
                if(c[f]) continue;
                q.push({f,s + 1});
            }
        }
    }
    
    int score = 55;
    int cnt = 0;
    for(int i = 1; i<=n; i++) {
        if(ans[i] < score){
            score = ans[i];
            cnt = 1;
        }
        else if(ans[i] == score) cnt++;
    }
    cout << score << ' ' << cnt << '\n';
    
    for(int i = 1; i<=n; i++){
        if(ans[i] == score) cout << i << ' ';
    }
    return 0;
}