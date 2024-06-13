#include<iostream>
using namespace std;
int n,m;
int main()
{
    cin >> n >> m;
    if(n == 1) cout << 1;
    else if(n == 2) cout << min(4,(m+1) /2);
    else{
        if(m > 6) cout << m-2;
        else cout << min(4,m);
    }
    return 0;
}