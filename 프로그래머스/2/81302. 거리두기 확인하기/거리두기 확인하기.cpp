#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int arr[5][5];
int visit[5][5];

bool inrange(int x, int y){
    return x>=0 && x<5 && y>=0 && y<5;
}

//P(응시자)는 1 / O(빈테이블)는 0 / X(파티션)는 2로
int check(vector<string> p){
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            if(p[i][j] == 'P') arr[i][j] = 1;
            else if(p[i][j] == 'O') arr[i][j] = 0;
            else arr[i][j] = 2;
        }
    }
    
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            if(arr[i][j] == 1){
                for(int k = 0; k<5; k++) fill(visit[k],visit[k]+5,0);
                queue<tuple<int,int,int>>q;
                q.push({i,j,0});
                visit[i][j] = 1;
                while(!q.empty()){
                    int cx,cy,d;
                    tie(cx,cy,d) = q.front();
                    q.pop();
                    for(int i = 0; i<4; i++){
                        int nx = cx + dx[i];
                        int ny = cy + dy[i];
                        if(!inrange(nx,ny) || visit[nx][ny]) continue;
                        if(arr[nx][ny] == 2) continue;
                        if(arr[nx][ny] == 1 && d+1 <= 2) return 0;
                        visit[nx][ny] = 1;
                        q.push({nx,ny,d+1});
                    }
                }
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int s = 0; s < 5; s++){
        if(check(places[s])) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}