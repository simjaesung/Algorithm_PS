#include<iostream>
using namespace std;
int n,m,st,en;
int arr[100005];

int check(int k){
    int tmp = 0, r = 1;
    for(int i = 0; i<n; i++){
        if(tmp + arr[i] > k){
            tmp = 0;
            r++;
        }
        if(arr[i] > k) return m + 1;
        tmp += arr[i];
    }
    return r;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
        en += arr[i];
    }
    while(st <= en){
        int mid = (st + en) / 2;
        if(check(mid) > m) st = mid + 1;
        else en = mid - 1;
    }
    cout << st;
    return 0;
}