#include<iostream>
#include<vector>
#include <cmath>
#include<queue>
using namespace std;
double cost[105][105];
vector<pair<double,double>>v;
priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>>pq;
int n,visit[105];
double a,b,ans;

//두점 사이의 거리 : 비용
double calCost(pair<double,double>p1, pair<double,double>p2){
    double dis = sqrt(pow(p1.first-p2.first,2) + pow(p1.second-p2.second,2));
    return round(dis * 100) / 100;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) cost[i+1][j+1] = calCost(v[i],v[j]);
    }
    
    visit[1] = 1;
    for(int i = 2; i<=n; i++) pq.push({cost[1][i],i});
    
    int cnt = 0;
    while(cnt < n-1){
        double tmp1 = pq.top().first;
        int tmp2 = pq.top().second;
        pq.pop();
        if(visit[tmp2]) continue;
        visit[tmp2] = 1;
        cnt++;
        ans += tmp1;
        for(int i = 1; i<=n; i++){
            if(!visit[i]) pq.push({cost[tmp2][i],i});
        }
    }
    cout << ans;
    return 0;
}
