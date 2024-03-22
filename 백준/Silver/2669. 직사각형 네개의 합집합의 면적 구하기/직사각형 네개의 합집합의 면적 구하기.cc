#include<iostream>
using namespace std;
int arr[105][105];
int x1,y1,x2,y2,ans;

int main()
{
    for(int i = 0; i<4; i++) {
        cin >> x1 >> y1 >> x2 >>y2;
        for(int s = y1; s < y2; s++ ){
            for(int k = x1; k < x2; k++) arr[s][k] = 1;
        }
    }
    
    for(int i = 1; i<=100; i++){
        for(int j = 1; j <= 100; j++) {
            if(arr[i][j]) ans ++;
        }
    }
    
    cout << ans;
    
    return 0;
}