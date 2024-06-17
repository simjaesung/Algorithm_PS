#include<iostream>
using namespace std;

int arr[1005][1005];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int c,r,k;

bool inrange(int x, int y){
    return x >=1 && x <= r && y >=1 && y <= c;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> c >> r >> k;
    if(k > c * r){
        cout << 0;
        return 0;
    }
    
    int cx = r; int cy = 1; //현재위치
    int val = 1; 
    int d = 0; //방향
    
    while(val <= c * r){
        if(val == k){
            cout << cy << ' ' << r - cx + 1 ;
            return 0;
        }
        arr[cx][cy] = val++;
        int nx = cx + dx[d];
        int ny = cy + dy[d];
        if(!inrange(nx,ny) || arr[nx][ny]) {
            d = (d + 1) % 4;
            cx += dx[d];
            cy += dy[d];
        }
        else {
            cx = nx;
            cy = ny;
        }
    }
    return 0;
}