#include<iostream>
#include<queue>
using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
int cost[1005][1005],visit[1005];
long long n,val,ans;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> val;
            cost[i][j] = val;
        }
    }
    
    visit[1] = 1;
    for(int i = 2; i<=n; i++) pq.push({cost[1][i],i});
    
    while(!pq.empty()){
        int tmp1 = pq.top().first; //다음비용
        int tmp2 = pq.top().second; //다음행성번호
        pq.pop();
        if(visit[tmp2]) continue;
        ans += tmp1;
        visit[tmp2] = 1;
        for(int i = 1; i<=n; i++){
            if(i == tmp2 || visit[i]) continue;
            pq.push({cost[tmp2][i],i});
        }
    }
    cout << ans;
    return 0;
}