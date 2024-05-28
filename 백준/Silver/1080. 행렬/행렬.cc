#include<iostream>
using namespace std;
int a[55][55], b[55][55];
string s;
int n,m,ans;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> s;
        for(int j = 0; j<m; j++) a[i][j] = s[j] -'0';
    }
    
    for(int i = 0; i<n; i++){
        cin >> s;
        for(int j = 0; j<m; j++) b[i][j] = s[j]-'0';
    }
    
    for(int i = 0; i<n-2; i++){
        for(int j = 0; j<m-2; j++){
            if(a[i][j] != b[i][j]){
                for(int s = i; s<= i+2; s++){
                    for(int l = j; l<= j+2; l++) 
                        a[s][l] = (a[s][l] - 1) * -1;
                }
                ans++;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i][j] != b[i][j]){
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}