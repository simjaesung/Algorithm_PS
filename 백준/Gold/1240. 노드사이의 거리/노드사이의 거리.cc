#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int arr[1005][1005],visit[1005];
vector<int>v[1005];
int n,m,a,b,c;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n-1; i++){
        cin >> a >> b >> c;
        v[a].push_back(b);
        v[b].push_back(a);
        arr[a][b] = c;
        arr[b][a] = c;
    }
    
    while(m--){
        cin >> a >> b;
        fill(visit,visit+1005,0);
        queue<pair<int,int>>q;
        q.push({a,0});
        while(!q.empty()){
            int cx = q.front().first;
            int d = q.front().second;
            q.pop();
            if(cx == b){
                cout << d << '\n';
                break;
            }
            visit[cx] = 1;
            for(auto nx : v[cx]){
                if(visit[nx]) continue;
                q.push({nx,d + arr[cx][nx]});
            }
        }
        
    }
    
    return 0;
}