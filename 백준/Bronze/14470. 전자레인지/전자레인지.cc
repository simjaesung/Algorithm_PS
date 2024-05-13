#include<iostream>
using namespace std;
int a,b,c,d,e,ans;
int main()
{
    cin >> a >> b >> c >> d >> e;
    if(a <= 0){
        ans += c * (0 - a);
        ans += d;
        a = 0;
    }
    ans +=(b - a) * e;
    cout << ans;
    return 0;
}