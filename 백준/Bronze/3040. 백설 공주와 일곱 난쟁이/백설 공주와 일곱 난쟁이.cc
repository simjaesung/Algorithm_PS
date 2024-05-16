#include<iostream>
using namespace std;
int arr[10],c[10];

void go(int p, int sum){
    
    if(p > 7 || sum > 100) return;
    
    if(p == 7 && sum == 100){
        for(int i = 0; i<9; i++){
            if(c[i]) cout << arr[i] << '\n';
        }
        exit(0);
    }
    
    for(int i = 0; i<9; i++){
        if(c[i]) continue;
        c[i] = 1;
        if(sum + arr[i] <= 100) go(p+1,sum+arr[i]);
        c[i] = 0;
    }
    
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i<9; i++) cin >> arr[i];
    go(0,0);
    return 0;
}