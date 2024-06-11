#include<iostream>
using namespace std;
int arr[1005][1005];
int n,k,ans1,ans2;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    int a = 1, b = 1;
    int cn = n;
    int cnt = 0;
    int dr = 0; 
    
    for(int i = n*n; i>=1; i--){
        cnt++;
        arr[a][b] = i;
        if(cnt == cn) {
            dr++;
            cnt = 1;
        }
        if(i == (cn - 2) * (cn-2) + 1) {
            cn -= 2;
            dr = 0;
            cnt = 0;
        }
        a += dx[dr];
        b += dy[dr];
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++) {
            cout << arr[i][j] << ' ';
            if(arr[i][j] == k){
                ans1 = i; ans2 = j;
            }
        }
        cout << '\n';
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}