#include<iostream>
using namespace std;
int n,p,tmp,ans;
int arr[100];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> p;
    tmp = n;
    while(1){
        tmp = (tmp * n) % p;
        if(arr[tmp] == 2) break;
        arr[tmp]++;
    }
    for(int i = 0; i<p; i++){
        if(arr[i] == 2) ans++;
    }
    cout << ans;
    return 0;
}