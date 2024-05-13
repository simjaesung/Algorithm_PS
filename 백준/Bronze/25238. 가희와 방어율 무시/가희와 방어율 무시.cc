#include<iostream>
using namespace std;
double a,b;

int main()
{
    cin >> a >> b;
    if(!b){
        if(a >= 100) cout << 0;
        else cout << 1;
    }
    else{
        double tmp = a * b / 100;
        if(a - tmp >= 100) cout << 0;
        else cout << 1;
    }
    return 0;
}