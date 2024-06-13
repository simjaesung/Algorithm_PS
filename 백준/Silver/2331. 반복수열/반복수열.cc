#include<iostream>
#include<cmath>
using namespace std;
int a,p,ans;
int arr[250000];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> a >> p;
    while(1){
        arr[a]++;
        if(arr[a] > 2) break;
        int tmp = 0;
        while(a > 0){
            tmp += pow(a % 10,p);
            a /= 10;
        }
        a = tmp;
    }
    
    for(int i = 0; i<250000; i++) if(arr[i] == 1) ans++;
    cout << ans;
    return 0;
}