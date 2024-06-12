#include<iostream>
using namespace std;
int arr[105];
int n,p,sex,k;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> arr[i];
    cin >> p;
    while(p--){
        cin >> sex >> k;
        if(sex == 1){
            for(int i = k; i<=n; i+=k){
                if(arr[i] == 1) arr[i] = 0;
                else arr[i] = 1;
            }
        }
        else{
            int l = k;
            int r = k;
            while(l-1 >=1 && r+1 <=n){
                if(arr[l-1] == arr[r+1]){
                    l--; r++;
                }
                else break;
            }
            for(int i = l; i<=r; i++){
                if(arr[i] == 1) arr[i] = 0;
                else arr[i] = 1;
            }
        }
    }
    for(int i = 1; i<=n; i++){
        cout << arr[i] << ' ';
        if(i % 20 == 0) cout << '\n';
    }
    return 0;
}