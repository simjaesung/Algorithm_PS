#include<iostream>
using namespace std;
int n,val,tmp,ans;

int main()
{
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> val;
        if(val) ans += ++tmp;
        else tmp = 0;
    }
    cout << ans;
    return 0;
}