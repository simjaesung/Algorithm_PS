#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>>v(55);
vector<int>p(55);
int n,val;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    
    sort(v.begin(), v.begin() + n);

    for(int i = 0; i<n; i++){
        p[v[i].second] = i;
    }
    
    for(int i = 0; i<n; i++){
        cout << p[i] << ' ';
    }
    
    return 0;
}