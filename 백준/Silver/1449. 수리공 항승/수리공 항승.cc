#include<iostream>
using namespace std;
int n, l, val,ans;
int h[1005];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        cin >> val;
        h[val] = 1;
    }
    
    for(int i = 1; i<=1000; i++){
        if(h[i]){
            ans++;
            int tmp = min(i + l, 1001);
            for(int k = i; k < tmp; k++) h[k] = 0;
        }
    }
    cout << ans;
}