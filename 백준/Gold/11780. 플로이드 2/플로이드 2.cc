#include<iostream>
#include<vector>
using namespace std;
const int inf = 0x3f3f3f3f;
int ans[105][105],nxt[105][105];
int n,m,a,b,c;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++) ans[i][j] = inf;
        ans[i][i] = 0;
    }
    while(m--){
        cin >> a >> b >> c;
        ans[a][b] = min(ans[a][b],c);
        if(ans[a][b] > c) ans[a][b] = c;
        nxt[a][b] = b;
    }
    
    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(ans[i][j] > ans[i][k] + ans[k][j]){
                    ans[i][j] = ans[i][k] + ans[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++) {
            if(ans[i][j] == inf) cout << 0 << ' ';
            else cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++) {
            if(ans[i][j] == 0 || ans[i][j] == inf){
                cout << 0 <<'\n'; continue;
            }
            vector<int>v;
            v.push_back(i);
            int tmp = nxt[i][j];
            while(tmp != j){
                v.push_back(tmp);
                tmp = nxt[tmp][j];
            }
            v.push_back(j);
            cout << v.size() << ' ';
            for(auto x : v) cout << x << ' ';
            cout << '\n';
        }
    }
    return 0;
}