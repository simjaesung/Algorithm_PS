#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int n,m,a,b,tmp,max_ans;
vector<int>arr[10002];
int ans[10002], c[10002];

void bfs(int x){
    queue<int>q;
    q.push(x);
    c[x] = 1;
    while(!q.empty()){
        int cx = q.front();
        q.pop();
        ans[cx]++;
        max_ans = max(ans[cx],max_ans);
        
        for(auto k : arr[cx]){
            if(!c[k]) {
                q.push(k);
                c[k] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        arr[a].push_back(b);
    }
    
    for(int i = 1; i<=n; i++){
        fill(c,c+10002,0);
        bfs(i);
    }
    
    for(int i = 1; i <= n; i++) {
        if(ans[i] == max_ans) cout << i << ' ';
    }
    
    return 0;
}