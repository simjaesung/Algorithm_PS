#include <iostream>
using namespace std;
int arr[100005];
int n,ans1,ans2;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    
    //증가상태에서 가장 긴 구간 구하기
    int tmp1 = 1;
    for(int i=1; i<n; i++){
        if(arr[i-1] <= arr[i]) {
            tmp1++;
        }
        else {
            ans1 = max(ans1,tmp1);
            tmp1 = 1;
        }
    }
    ans1 = max(ans1,tmp1);
    
    //감소상태에서 가장 긴 구간 구하기
    int tmp2 = 1;
    for(int i=1; i<n; i++){
        if(arr[i-1] >= arr[i]) tmp2++;
        else {
            ans2 = max(ans2,tmp2);
            tmp2 = 1;
        }
    }
    ans2 = max(ans2,tmp2);
    
    cout << max(ans1,ans2);
}
    