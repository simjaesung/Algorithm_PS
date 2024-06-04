#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,d,k,c,ans;
int arr[60005]; //벨트에 놓인 초밥
int cho[3005]; //초밥 종류
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> d >> k >> c;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = n; i<2*n; i++) arr[i] = arr[i-n];
    
    for(int i = 0; i<=n; i++){
        fill(cho, cho + d + 1, 0);
        int tmp = 0;
        cho[c] = 1;
        for(int j = i; j<i+k;j++) cho[arr[j]] = 1;
        for(int k = 1; k<=d; k++) if(cho[k]) tmp++;
        ans = max(tmp,ans);
    }
    cout << ans;
    return 0;
}