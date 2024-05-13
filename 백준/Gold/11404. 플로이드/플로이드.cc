#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a,b,c;
int ans[105][105];
const int inf = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
        fill(ans[i], ans[i]+n+1, inf);
    
    for(int i = 1; i<=n; i++) ans[i][i] = 0;
    
    for(int i = 0; i<m; i++){
        cin >> a >> b >> c;
        ans[a][b] = min(ans[a][b],c);
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            for(int k = 1; k<=n; k++){
                ans[j][k] = min(ans[j][k], ans[j][i] + ans[i][k]);
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
    
    return 0;
}