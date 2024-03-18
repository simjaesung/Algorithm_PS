#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll arr[10005];
ll n,m,s,e,sum;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++) cin >> arr[i];
    cin >> m;
    
    sort(arr, arr+n);
    
    s = 0; e = arr[n-1];
    while(s <= e){
        ll mid = (s + e) / 2;
        ll tmp = 0;
        for(int i = 0; i < n; i++){
            tmp += min(mid, arr[i]);
        }
        if(tmp > m) e = mid - 1;
        else s = mid + 1;
    }
    
    cout << s - 1;
    return 0;
}