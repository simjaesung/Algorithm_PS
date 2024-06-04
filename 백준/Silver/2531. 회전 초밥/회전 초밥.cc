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
    
    int s = 0; int e = k-1;
    for(int i = s; i<=e; i++) cho[arr[i]]++;
    cho[c]++;
    
    while(s < n){
        int tmp = 0;
        for(int i = 1; i<=d; i++) if(cho[i]) tmp++;
        ans = max(ans,tmp);
        cho[arr[s]]--;
        s++; e++;
        cho[arr[e]]++;
    }
    cout << ans;
    return 0;
}