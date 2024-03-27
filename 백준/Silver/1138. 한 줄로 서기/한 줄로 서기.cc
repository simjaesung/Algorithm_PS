#include<iostream>
using namespace std;
int arr[15],ans[15];
int n;

int main()
{
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> arr[i];
    
    for(int i = 1; i<=n; i++) {
        int tmp = arr[i];
        int idx = 1;
        
        while(1){
            if(ans[idx] == 0) {
                if(tmp == 0) break;
                else tmp --;
            }
            idx++;
        }
        ans[idx] = i;
    }
    for(int i = 1; i<=n; i++) cout << ans[i] << ' ';
    
    return 0;
}