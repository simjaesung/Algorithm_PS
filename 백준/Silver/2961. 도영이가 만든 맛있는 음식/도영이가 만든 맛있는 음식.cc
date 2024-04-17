#include<iostream>
#include<limits.h>
using namespace std;
typedef long long ll;

int n, arr[15][2], c[15];
ll ans = LLONG_MAX;

//a는 신맛 b는 쓴맛
void go(ll a, ll b)
{
    if(a > 0 && b > 0) ans = min(abs(a-b),ans);
    
    for(int i = 0; i < n; i++) {
        ll shin = arr[i][0];
        ll ssn = arr[i][1];
        if(c[i]) continue;
        
        c[i] = 1;
        a *= shin;
        b += ssn;
        go(a,b);
        
        c[i] = 0;
        a /= shin;
        b -= ssn;
    }
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    
    go(1,0);
    cout << ans;
    return 0;
}