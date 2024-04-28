#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int sosoo(ll val)
{
    if(val < 2) return 0;
    ll sqrtval = sqrt(val);
    for(ll i = 2; i<= sqrtval; i++){
        if(val % i == 0) return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        ll tmp; cin >> tmp;
        while(!sosoo(tmp)) tmp++;
        cout << tmp <<'\n';
    }
    return 0;
}