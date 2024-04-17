#include<iostream>
#include<limits.h>
using namespace std;
typedef long long ll;

int n, arr[15][2];
ll ans = LLONG_MAX;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    
    for(int i = 1; i<(1<<n); i++){
        ll a = 1, b = 0;
        for(int k = 0; k < n; k++){
            if(i & (1 << k)){
                a *= arr[k][0];
                b += arr[k][1];
            }
        }
        ans = min(abs(a-b),ans);
    }
    cout << ans;
    return 0;
}