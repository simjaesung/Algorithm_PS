#include<iostream>
using namespace std;
int A[5], B[5];
int n,a,b,val;

int main()
{   
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(n--){
        for(int i = 1; i<=4; i++) {
            A[i] = 0; B[i] = 0;
        }
        
        cin >> a;
        for(int i = 0; i<a; i++) {
            cin >> val;
            A[val]++;
        }
        
        cin >> b;
        for(int i = 0; i<b; i++) {
            cin >> val;
            B[val]++;
        }
        
        if(A[4] != B[4]){
            if(A[4] > B[4]) cout << "A\n";
            else cout << "B\n";
        }
        else if(A[3] != B[3]){
            if(A[3] > B[3]) cout << "A\n";
            else cout << "B\n";
            
        }
        else if(A[2] != B[2]){
            if(A[2] > B[2]) cout << "A\n";
            else cout << "B\n";
        }
        else if(A[1] != B[1]){
            if(A[1] > B[1]) cout << "A\n";
            else cout << "B\n";
        }
        else cout << "D\n";
    }
    return 0;
}