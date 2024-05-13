#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
int n;
ll ans;
string s;
map<char,ll>val,tmp;
vector<pair<ll,char>>v;
vector<string>v_s;

bool cmp(pair<ll,char>a, pair<ll,char>b){
    return a.first > b.first;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(n--){
        cin >> s;
        v_s.push_back(s);
        int len = s.length();
        for(int i = 0; i<s.length(); i++) tmp[s[i]] += pow(10,len--);
    }
    
    for(auto x : tmp) v.push_back({x.second,x.first});
    sort(v.begin(), v.end(),cmp); //정렬을 통해 가장 큰 숫자를 부여할 알파벳을 찾는다
    
    int k = 9;
    for(auto x : v) val[x.second] = k--;
    
    for(auto x : v_s){
        int len = x.length() - 1;
        ll tmp2 = 0;
        for(int i = 0; i<x.length(); i++){
            tmp2 += val[x[i]] * pow(10,len--);
        }
        ans += tmp2;
    }
    cout << ans;
    return 0;
}