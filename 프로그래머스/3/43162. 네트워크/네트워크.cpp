#include <string>
#include <vector>

using namespace std;
vector<vector<int>>cc;
int visit[205], arr[205][205];
int cn,answer = 0;

void dfs(int r){
    visit[r] = 1;
    for(int i = 0; i<cn; i++){
        if(cc[r][i] && !visit[i]) dfs(i);
    }
}

int solution(int n, vector<vector<int>> c) {
    cc = c;
    cn = n;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) if(c[i][j]) arr[i][j] = 1;
    }
    
    for(int i = 0; i<n; i++){
        if(!visit[i]){
            answer++;
            dfs(i);
        }
    }
    return answer;
}