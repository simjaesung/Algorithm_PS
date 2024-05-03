#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n,a,b,visit[100005];
vector<int>v[100005];
vector<int>check;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i=0; i<n; i++){
        cin >> a; check.push_back(a);
    }
    if(check[0] !=1 ) { cout<< 0; return 0; }
    
    queue<int>q;
    q.push(1);
    visit[1] = 1;
    int idx = 1;
    while(!q.empty()){
        int cx = q.front();
        q.pop();
        
        int tmp = 0;
        for(auto nx : v[cx]){
            if(!visit[nx]) {
                visit[nx] = 1;
                tmp++;
            }
        }
        
        for(int i=idx; i<idx+tmp; i++){
            if(!visit[check[i]]){
                cout << 0;
                return 0;
            }
            else q.push(check[i]);
        }
        
        idx += tmp;
    }
    cout << 1;
    return 0;
}