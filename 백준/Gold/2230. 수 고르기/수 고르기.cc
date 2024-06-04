#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
int n,m,ans = INT_MAX;
int arr[100005];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);    
    cin >> n >> m;
    for(int i = 0; i<n; i++) cin >> arr[i];
    sort(arr,arr+n);
    int s = 0; int e = 0;
    while(s < n && e < n){
        if(arr[e] - arr[s] >= m){
            ans = min(arr[e]-arr[s],ans);
            s++;
        }
        else e++;
    }
    cout << ans;
    return 0;
}