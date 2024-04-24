#include<iostream>
#include<string>
using namespace std;
string a,b,mina,minb,maxa,maxb;

int main()
{
    cin >> a >> b;
    for(int i = 0; i < a.length(); i++){
        if(a[i] == '5'){
            mina += a[i];
            maxa += '6';
        }
        else if(a[i] == '6'){
            mina += '5';
            maxa += a[i];
        }
        else {
            mina += a[i];
            maxa += a[i];
        }
    }
    
    for(int i = 0; i < b.length(); i++){
        if(b[i] == '5'){
            minb += b[i];
            maxb += '6';
        }
        else if(b[i] == '6'){
            minb += '5';
            maxb += b[i];
        }
        else {
            minb += b[i];
            maxb += b[i];
        }
    }
    cout << stoi(mina) + stoi(minb) <<' ' << stoi(maxa) + stoi(maxb) << '\n';
    return 0;
}