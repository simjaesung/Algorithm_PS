#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
vector<int>arr;
int n,tmp,ans1,ans2,f = INT_MAX;
int s, e;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
	for(int i = 0; i<n; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    
    s = 0; e = n - 1;
    while(s < e){
        if(f > abs(arr[s] + arr[e])){
            f = abs(arr[s] + arr[e]);
            ans1 = arr[s]; 
            ans2 = arr[e];
        }
        
        if(arr[s] + arr[e] < 0) s++;
        else e--;
    }
    cout << ans1 << ' ' <<ans2;
    
	return 0;
}