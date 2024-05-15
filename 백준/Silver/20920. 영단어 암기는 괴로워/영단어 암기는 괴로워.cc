#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
int n,m;
string s;
unordered_map<string,int>map;
vector<pair<string,int>>v;

bool cmp(const pair<string,int>&a, const pair<string,int>&b){
    if(a.second != b.second) return a.second > b.second;
    else {
        if(a.first.length() != b.first.length()) 
            return a.first.length() > b.first.length();
        else return a < b;
    }
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while(n--){
        cin >> s;
        if(s.length() < m) continue;
        map[s]++;
    }
    for(auto x : map) v.push_back({x.first,x.second});
    sort(v.begin(), v.end(),cmp);
    for(auto x : v) cout << x.first << '\n';
    
    return 0;
}
