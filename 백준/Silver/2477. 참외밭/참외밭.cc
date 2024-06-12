#include<iostream>
#include<vector>
using namespace std;
int c[4];
int k,d,l,s,sz = 1;
vector<pair<int,int>>v;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> k;
    for(int i = 0; i<6; i++){
        cin >> d >> l;
        c[d-1]++;
        v.push_back({d,l});
    }
    
    for(int i = 0; i<6; i++){
        int a = v[i].first;
        int b = v[i].second;
        if(c[a-1] == 1) {
            sz *= b;
            s = i;
        }
    }
    if(s == 5 && c[v[0].first-1] == 1) s = 0;
    int tmp = v[(s+2)%6].second * v[(s+3)%6].second;
    cout << (sz-tmp) * k;
    return 0;
}