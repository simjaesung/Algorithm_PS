#include<iostream>
#include<vector>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> q;
int taken[32005];
vector<int>v[32005];
int n,m,a,b;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        taken[b]++;
        v[a].push_back(b);
    }
    
    for(int i = 1; i<=n; i++){
        if(!taken[i]) q.push(i);
    }
    
    while(!q.empty()){
        int val = q.top(); q.pop();
        cout << val << ' ';
        for(auto x : v[val]){
            taken[x]--;
            if(!taken[x]) q.push(x);
        }
    }
    return 0;
}