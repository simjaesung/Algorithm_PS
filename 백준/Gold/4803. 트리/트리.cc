#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,a,b,cnt,ans,check;
vector<int>v[505];
int c[505]; //방문기록

void dfs(int x, int prev){
    c[x] = 1;
    for(auto k : v[x]){
        if(k == prev) continue;
        if(c[k]) check = 1;
        else dfs(k,x);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        cin >> n >> m;
        if(!n && !m) break;
        for(int i = 1; i<=n; i++) v[i].clear();
        fill(c,c+505,0); 
        cnt++; 
        ans = 0;
        
        for(int i = 0; i< m; i++){
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        for(int i = 1; i<=n; i++){
            if(c[i]) continue;
            check = 0;
            dfs(i, 0);
            if(!check) ans++;
        }
        
        if(ans == 0) cout << "Case " << cnt <<": No trees.\n";
        else if(ans == 1) cout << "Case " << cnt <<": There is one tree.\n";
        else cout << "Case " << cnt <<": A forest of "<< ans <<" trees.\n";
    }   
    
    return 0;
}