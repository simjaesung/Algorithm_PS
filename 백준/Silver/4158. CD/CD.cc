#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n1,n2,val,ans;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    while(1){
        cin >> n1 >> n2;
        if(n1 == 0 && n2 == 0) break;
        ans = 0;
        vector<int>a;
        for(int i = 0; i<n1; i++){
            cin >> val; a.push_back(val);
        }
        for(int i = 0; i<n2; i++){
            cin >> val; 
            int k = lower_bound(a.begin(),a.end(), val) - a.begin();
            if(a[k] == val) ans++;
        }
        cout << ans<<'\n';
    }
}