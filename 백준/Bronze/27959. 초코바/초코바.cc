#include<iostream>
using namespace std;
int n,m;

int main()
{
    cin >> n >> m;
    if(n * 100 < m) cout << "No";
    else cout << "Yes";
    
    return 0;
}