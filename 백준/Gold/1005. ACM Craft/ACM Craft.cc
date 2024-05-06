#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,m,k,a,b,last;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        int tim[1005] = {0,};//건물 짓는데 걸리는 시간
        int c[1005] = {0,}; //선행건물 개수
        int tot[1005] = {0,}; //총걸리는 시간
        vector<int>p[1005]; //선행 관계
        
        for(int i = 1; i<=n; i++){
            cin >> k; tim[i] = k;
        }
        
        for(int i = 0; i<m; i++){
            cin >> a >> b;
            p[a].push_back(b);
            c[b]++;
        }
        cin >> last;
        
        int ans = 0;
        queue<int>q;
        
        for(int i = 1; i<=n; i++){
            if(!c[i]) q.push(i);
        }
        
        while(!q.empty()){
            int tmp = q.front(); q.pop();
            for(auto x : p[tmp]){
                tot[x] = max(tot[x], tim[tmp] + tot[tmp]);
                c[x]--;
                if(!c[x]) q.push(x);
            }
        }
        cout << tot[last] + tim[last] <<'\n';
    }
    return 0;
}
