#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int visit[105], c[105][105],answer;
vector<int>v[105];

void bfs(int r){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    for(int i = 0; i<v[r].size(); i++) pq.push({c[r][v[r][i]],v[r][i]}); //비용,다음
    visit[r] = 1;
    while(!pq.empty()){
        int k = pq.top().first;
        int nxt = pq.top().second;
        pq.pop();
        if(visit[nxt]) continue;
        answer += k;
        visit[nxt] = 1;
        for(int i = 0; i<v[nxt].size(); i++){
            if(!visit[v[nxt][i]]) pq.push({c[nxt][v[nxt][i]],v[nxt][i]});
        }
    }
    
}

int solution(int n, vector<vector<int>> costs) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    
    for(int i = 0; i<costs.size(); i++) {
        c[costs[i][0]][costs[i][1]] = costs[i][2];
        c[costs[i][1]][costs[i][0]] = costs[i][2];
        v[costs[i][0]].push_back(costs[i][1]);
        v[costs[i][1]].push_back(costs[i][0]);
    }
    bfs(0);
   
    return answer;
}