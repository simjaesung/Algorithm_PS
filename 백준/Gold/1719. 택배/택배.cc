#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a,b,c;
const int inf = 0x3f3f3f3f;
int arr[205][205], d[205][205];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        fill(arr[i]+1,arr[i]+n+1,inf);
        arr[i][i] = 0;
    }
    
    while(m--){
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b],c);
        arr[b][a] = min(arr[b][a],c);
        d[a][b] = b;
        d[b][a] = a;
    }
    
    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                    d[i][j] = d[i][k];
                }
            }
        }
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(!d[i][j]) cout << "- ";
            else cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}