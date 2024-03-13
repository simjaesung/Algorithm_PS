#include<iostream>
using namespace std;
typedef long long ll;

ll mod(ll a, ll b, ll c) 
{
	if (b == 1) return a % c;
	ll val = mod(a, b / 2, c);
	val = val * val % c;
	if (b % 2 == 1) return val * a % c;
	else return val;
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	ll a, b, c;
	cin >> a >> b >> c;

	cout << mod(a, b, c);
	return 0;
}