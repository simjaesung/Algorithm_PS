#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,k,c;
vector<pair<int,int>>v;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    
    for(int i = 0; i< n; i++){
        int g,s,d,val;
        cin >> c >> g >> s >> d;
        val = 100 * g + 10 * s + d;
        v.push_back({val,c});
    }
    
    sort(v.begin(), v.end());
    
    if(v[v.size()-1].second == k){
        cout << 1;
        return 0;
    }
    
    int ans = 1;
    
    for(int i = v.size() - 2; i >= 0; i-- ){
        if(v[i+1].first != v[i].first) 
            ans = v.size() - i;
        
        if(v[i].second == k) {
            cout << ans;
            return 0;
        }
    }
    return 0;
}