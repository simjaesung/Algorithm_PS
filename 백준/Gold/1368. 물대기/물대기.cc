#include<iostream>
#include<queue>
using namespace std;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
int visit[305],cost[305][305];
int n,val,ans,cnt;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> val;
        cost[i][n+1] = val;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> val;
            cost[i][j] = val;
        }
    }
    
    visit[n+1] = 1;
    for(int i = 1; i<=n; i++) pq.push({cost[i][n+1],i});
    
    while(cnt < n){
        int tmp1 = pq.top().first;
        int tmp2 = pq.top().second;
        pq.pop();
        if(visit[tmp2]) continue;
        cnt++;
        ans += tmp1;
        visit[tmp2] = 1;
        for(int i = 1; i<=n+1; i++) {
            if(!visit[i]) pq.push({cost[tmp2][i],i});
        }
    }
    
    cout << ans;
    return 0;
}