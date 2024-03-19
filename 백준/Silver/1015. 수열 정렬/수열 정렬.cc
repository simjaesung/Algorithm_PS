#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int>v1,v2;
vector<queue<int>>v3(1005);
int n,val;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> val;
        v1.push_back(val);
        v2.push_back(val);
    }
    
    sort(v2.begin(), v2.end());
    
    for(int i = 0; i<n; i++){
        v3[v2[i]].push(i);
    }
    
    for(int i = 0; i < n; i++){
        cout << v3[v1[i]].front() <<' ';
        v3[v1[i]].pop();
    }
    
    
    return 0;
}