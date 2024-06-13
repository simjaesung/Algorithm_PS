#include<iostream>
using namespace std;
int n,ans1,ans2;
int arr[105][105];
int main()
{
    cin >> n;
    for(int i = 0; i<n; i++){
        string s; cin >> s;
        for(int j = 0; j<n; j++) {
            if(s[j] == '.') arr[i][j] = 1;
        }
    }
    
    for(int i = 0; i<n; i++){
        int cnt = 0;
        for(int j = 0; j<n; j++){
            if(arr[i][j]) cnt++;
            else{
                if(cnt > 1) ans1++;
                cnt = 0;
            }
        }
        if(cnt > 1) ans1++;
    }
    
    for(int i = 0; i<n; i++){
        int cnt = 0;
        for(int j = 0; j<n; j++){
            if(arr[j][i]) cnt++;
            else{
                if(cnt > 1) ans2++;
                cnt = 0;
            }
        }
        if(cnt > 1) ans2++;
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}