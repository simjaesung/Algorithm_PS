#include<iostream>
#include<algorithm>
using namespace std;
int n,m,r,val,a,b,l,result;
int ans[105][105],item[105];
const int inf = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> r;
    for(int i = 1; i<=n; i++) {
        cin >> item[i];
        fill(ans[i], ans[i] + 1 + n, inf);
        ans[i][i] = 0;
    }
    
    for(int i = 0; i<r; i++){
        cin >> a >> b >> l;
        ans[a][b] = min(ans[a][b],l);
        ans[b][a] = min(ans[b][a],l);
    }
    
    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
            }
        }
    }
    
    for(int i = 1; i<=n; i++){
        int tmp = 0;
        for(int j = 1; j<=n; j++) {
            if(ans[i][j] <= m) tmp+=item[j];
        }
        result = max(tmp, result);
    }
    cout << result;
    return 0;
}