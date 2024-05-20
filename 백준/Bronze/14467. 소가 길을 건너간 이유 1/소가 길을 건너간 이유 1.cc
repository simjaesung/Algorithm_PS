#include<iostream>
using namespace std;
int arr[15];
int n,a,b,ans;
int main()
{
    for(int i=1; i<=10; i++) arr[i] = -1;
    cin >> n;
    while(n--){
        cin >> a >> b;
        if(arr[a] != -1 && arr[a] != b) ans++;
        arr[a] = b;
    }
    cout << ans;
    
    return 0;
}