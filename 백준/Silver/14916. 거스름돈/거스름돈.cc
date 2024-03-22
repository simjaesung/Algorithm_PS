#include<iostream>
#include<limits.h>
using namespace std;
int n,ans = INT_MAX,tmp; //tmp는 5원 짜리

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(n >= 0){
        if(n % 2 == 0) ans = min(ans,tmp + n/2);
        n -= 5;
        tmp++;
    }
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}