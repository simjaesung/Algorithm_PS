#include<iostream>
using namespace std;
int n,s,e,tmp,ans;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    s = 1,e = 1;
    while(e <= n+1){
        if(tmp < n) tmp += e++;       
        else{
            if(tmp == n) ans++;
            tmp -= s++;
        }
    }
    cout << ans;
}