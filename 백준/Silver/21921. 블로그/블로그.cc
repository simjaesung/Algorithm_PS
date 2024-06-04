#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,x,sum,ans,cnt;
int arr[250005];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> x;
    
    for(int i = 1; i<=n; i++) cin >> arr[i];
    for(int i = 1; i<=x; i++) sum += arr[i];
    ans = sum; cnt = 1;
    
    int s = 2; int e = x + 1;
    while(e <=n){
        sum -= arr[s-1];
        sum += arr[e];
        if(sum > ans){
            ans = sum;
            cnt = 1;
        }
        else if(sum == ans) cnt++;
        s++; e++;
    }
    if(ans == 0) cout << "SAD";
    else cout <<ans << '\n' << cnt;
    return 0;
}