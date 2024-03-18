#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,l,val;
vector<int> v;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> l;
    for(int i = 0; i < n; i++) {
        cin >> val;
        v.push_back(val);
    }
    v.push_back(l);
    v.push_back(0);
    sort(v.begin(),v.end());
    
    int s = 1, e = l - 1;
    while(s <= e){
        val = 0;
        int mid = (s + e) / 2;
        for(int i = 1; i< v.size(); i++){
            int tmp = v[i] - v[i-1];
            val += tmp / mid;
            if(tmp % mid == 0) val--;
        }
        if(val > m) s = mid + 1;
        else e = mid - 1;
    }
    cout << s;
   
    return 0;
}
