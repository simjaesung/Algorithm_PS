#include<iostream>
using namespace std;
int n,m,b;
int ans1 = 0x7f7f7f7f,ans2;
int arr[505][505];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> b;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++) cin >> arr[i][j];
    }
    
    for(int h = 0; h<=256; h++){
        int hav = 0; //부셔야할 블록개수
        int need = 0; //쌓아야할 블록개수
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++) {
                if(arr[i][j] == h) continue;
                
                if(arr[i][j] > h) hav += arr[i][j] - h;
                else need += h - arr[i][j];
            }
        }
        //블록의 개수가 충분할 경우 최소시간인지 확인해야함
        if(hav + b >= need){
            if(2*hav + need <= ans1){
                ans1 = hav * 2 + need;
                ans2 = h;
            }
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}