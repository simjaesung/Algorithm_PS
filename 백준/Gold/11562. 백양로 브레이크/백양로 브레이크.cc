#include<iostream>
#include<algorithm>
using namespace std;
int n,m,u,v,b,k,s,e;
int arr[255][255];
const int inf = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        fill(arr[i] + 1, arr[i] + n + 1, inf);
        arr[i][i] = 0;
    }
    while(m--){
        cin >> u >> v >> b;
        arr[u][v] = 0;
        if(b) arr[v][u] = 0;
        else arr[v][u] = 1;
    }
    
    for(int l = 1; l<=n; l++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                arr[i][j] = min(arr[i][j], arr[i][l] + arr[l][j]);
            }
        }
    }
    
    cin >> k;
    while(k--){
        cin >> s >> e;
        cout << arr[s][e] << '\n';
    }
    return 0;
}