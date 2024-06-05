#include <string>
#include <vector>
using namespace std;
int answer = 100;
int tmp = 0;
int visit[105];
vector<int>v[105];

void dfs(int r){
    if(visit[r]) return;
    tmp++;
    visit[r] = 1;
    for(auto x : v[r]){
        if(!visit[x]) dfs(x);
    }
}

int solution(int n, vector<vector<int>>w) {
    for(int i = 0; i<n-1; i++){
        tmp = 0;
        for(int s = 1; s<=n; s++) {
            v[s].clear();
            visit[s] = 0;        
        }
        
        for(int j = 0; j<n-1; j++){
            if(i == j) continue;
            v[w[j][0]].push_back(w[j][1]);
            v[w[j][1]].push_back(w[j][0]);
        }
        dfs(1);
        answer = min(answer,abs(n-tmp-tmp));
    }
    return answer;
}