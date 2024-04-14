#include<iostream>
using namespace std;
double a,b,c;

int main()
{
    cin >> a >> b >> c;
    cout << int(max(a * b / c, a / b * c));
    return 0;
}