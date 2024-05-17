#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int inf = 0x3f3f3f3f;
int v,e,a,b,c,ans = inf;
int r[405][405];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> v >> e;
    for(int i = 1; i<=v; i++) {
        fill(r[i] + 1, r[i] + 1 + v, inf);
        r[i][i] = 0;
    }
    
    while(e--){
        cin >> a >> b >> c;
        r[a][b] = min(r[a][b],c);
    }
    
    for(int k = 1; k<=v; k++){
        for(int i = 1; i<=v; i++){
            for(int j = 1; j<=v; j++){
                r[i][j] = min(r[i][j], r[i][k] + r[k][j]);
            }
        }
    }
    
    for(int i = 1; i<=v; i++){
        for(int j = 1; j<=v; j++){
            if(i == j) continue;
            ans = min(ans, r[i][j] + r[j][i]);
        }
    }
    
    if(ans == inf) cout << -1;
    else cout << ans;
    return 0;
}