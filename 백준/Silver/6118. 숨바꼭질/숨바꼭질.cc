#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m,s,e,ans1,ans2,ans3;
vector<vector<int>>v(20005);
int c[20005];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while(m--){
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    queue<pair<int,int>>q;
    q.push({1,1});
    
    while(!q.empty()){
        int cx = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(c[cx]) continue;
        c[cx] = cnt;
        for(auto x : v[cx]){
            if(c[x]) continue;
            q.push({x,cnt + 1});
        }
    }
    
    int tmp = 0;
    for(int i = 1; i <= n; i++){
        if(tmp < c[i]){
            ans1 = i; //숨어야하는 헛간 중 가장 작은 번호
            tmp = c[i]; 
            ans2 = tmp - 1;//헛간 최대 거리 
            ans3 = 0; //같은 헛간 개수 초기화
        }
        if(tmp == c[i]) ans3++; //같은 헛간 개수
    }
    
    cout << ans1 << ' ' << ans2 << ' ' << ans3;
    
    return 0;
}