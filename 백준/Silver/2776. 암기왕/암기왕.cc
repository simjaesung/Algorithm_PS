#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,t,val;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        vector<int>v1,v2;
        cin >> n;
        for(int i = 0; i<n; i++){
            cin >> val;
            v1.push_back(val);
        }
        
        cin >> m;
        for(int i = 0; i<m; i++){
            cin >> val;
            v2.push_back(val);
        }
        
        sort(v1.begin(),v1.end());
        
         for(int i = 0; i<m; i++){
             int idx = lower_bound(v1.begin(),v1.end(),v2[i]) - v1.begin();
             if(v1[idx] == v2[i]) cout << 1 <<'\n';
             else cout << 0 << '\n';
        }
        
    }
    return 0;
}