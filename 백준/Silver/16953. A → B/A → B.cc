#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
ll a,b;
int bfs(ll k)
{
    queue<pair<ll,ll>>q;
    q.push({a,1});
    ll val, cnt, n1,n2;
    
    while(!q.empty()){
        val = q.front().first;
        cnt = q.front().second;
        n1 = val * 10 + 1;
        n2 = val * 2;
        q.pop();
        if(n1 == b || n2 == b) return cnt + 1;
        if(n1 < b) q.push({n1, cnt + 1});
        if(n2 < b) q.push({n2, cnt + 1});
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b;
    cout << bfs(a);
    return 0;
}