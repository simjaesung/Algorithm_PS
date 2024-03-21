#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int n,k,a,b,c;
long long ans;
multiset<pair<int,int>, greater<pair<int,int>>>ms;
multiset<int>back;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        //무게와 값어치
        cin >> a >> b;
        ms.insert({b,a});
    }
    
    for(int i = 0; i<k; i++){
        cin >> c;
        back.insert(c);
    }
    
    for(auto it = ms.begin(); it != ms.end(); it++){
        auto idx = back.lower_bound(it->second);
        if(idx != back.end()) {
            ans += it->first;
            back.erase(idx);
        }
    }
    cout << ans;
    
    return 0;
}