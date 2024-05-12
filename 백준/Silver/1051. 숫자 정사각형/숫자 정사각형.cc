#include<iostream>
using namespace std;
int n,m,a1,a2,b1,b2,c1,c2,ans = 1;
string s;
int arr[55][55];
bool inrange(int x, int y){
    return x > 0 && x <= n && y > 0 && y <= m;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> s;
        for(int j = 1; j<=m; j++) arr[i][j] = s[j-1] - '0';
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++) {
            a1 = i; a2 = j + 1;
            b1 = i + 1; b2 = j;
            c1 = i + 1; c2 = j + 1;
            int cnt = 2;
            while(1){
                if(!inrange(a1,a2) || !inrange(b1,b2) || !inrange(c1,c2)) break;
                if(arr[i][j] == arr[a1][a2] &&  arr[a1][a2] == arr[b1][b2] 
                   && arr[b1][b2] == arr[c1][c2]) ans = max(ans, cnt * cnt);
                a2++; b1++; c1++; c2++; cnt++;
            }
        }
    }
    cout << ans;
    return 0;
}