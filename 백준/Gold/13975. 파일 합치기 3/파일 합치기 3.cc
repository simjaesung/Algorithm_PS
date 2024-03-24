#include<iostream>
#include<queue>
using namespace std;
int t,n,val;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        ll ans = 0;
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        cin >> n;
        while(n--){
            cin >> val;
            pq.push(val);
        }
        while(pq.size() > 1){
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        cout << ans <<'\n';
        
    }
    return 0;
}