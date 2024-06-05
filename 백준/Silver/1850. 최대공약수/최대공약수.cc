#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a,b,k;

ll gcd(ll a, ll b){
    if(!b)return a;
    else return gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b;
    k = gcd(a,b);
    for(int i = 0; i<k; i++) cout << 1;
    return 0;
}