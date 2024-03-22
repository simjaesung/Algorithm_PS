#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,k,c;
vector<vector<int>>v;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    
    for(int i = 0; i< n; i++){
        int g,s,d,val;
        vector<int>tmp;
        cin >> c >> g >> s >> d;
        tmp.push_back(g);
        tmp.push_back(s);
        tmp.push_back(d);
        tmp.push_back(c);
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    
    if(v[v.size()-1][3] == k){
        cout << 1;
        return 0;
    }
    
    int ans = 1;
    for(int i = v.size() - 2; i >= 0; i-- ){
        for(int s = 0; s < 3; s++){
            if(v[i+1][s] != v[i][s])
                ans = v.size() - i;
        }
        
        if(v[i][3] == k) {
            cout << ans;
            return 0;
        }
    }
    return 0;
}