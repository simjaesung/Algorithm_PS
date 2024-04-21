#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string name[105],tmp;
int n,a,b,c;
vector<pair<int,pair<int,int>>>v1;
vector<pair<int,pair<int,int>>>v2;
int main()
{
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> tmp >> a >> b >> c;
        v1.push_back({c,{b,a}});
        v2.push_back({c,{b,a}});
        name[i] = tmp;
    }
    
    sort(v1.begin(),v1.end());
    
    for(int j = 0; j<n;j++){
        if(v1[n-1] == v2[j]) cout << name[j] <<'\n';
    }
    
    for(int j = 0; j<n;j++){
        if(v1[0] == v2[j]) cout << name[j] <<'\n';
    }
    return 0;
}