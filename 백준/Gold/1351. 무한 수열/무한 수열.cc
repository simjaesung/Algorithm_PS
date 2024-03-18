#include<iostream>
#include<unordered_map>
using namespace std;
typedef long long ll;
ll n, p, q;
unordered_map<ll, ll>um;

ll solve(ll n)
{
    if (um[n]) return um[n];
    um[n] = solve(n / p) + solve(n / q);
    return um[n];
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    um[0] = 1;
    cin >> n >> p >> q;
    cout << solve(n);
    return 0;
}