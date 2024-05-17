#include<iostream>
using namespace std;
int n;
int main()
{
    cin >> n;
    if(n == 1) {
        cout << "*" ;
        return 0;
    }
    for(int i = 0; i<2*n; i++){
        for(int j = 0; j<n; j++){
            if(j % 2 == 0){
                if(i % 2 == 0) cout << "*" ;
                else cout << " ";
            }
            else {
                if(i % 2 == 1) cout << "*" ;
                else cout << " ";
            }
        }
        cout << '\n';
    }
    
    return 0;
}