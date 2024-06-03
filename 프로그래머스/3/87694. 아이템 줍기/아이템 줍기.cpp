#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int arr[105][105],visit[105][105];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int solution(vector<vector<int>> rect, int cX, int cY, int iX, int iY) {
    int answer = 0;
    for(auto x : rect){
        for(int i = x[0]*2; i<=x[2]*2; i++){
            for(int j = x[1]*2; j<=x[3]*2; j++) arr[i][j] = 1;
        }
    }
    for(auto x : rect){
        for(int i = x[0]*2 + 1; i<x[2]*2; i++){
            for(int j = x[1]*2 + 1; j<x[3]*2; j++) arr[i][j] = 0;
        }
    }
    
    queue<tuple<int,int,int>>q;
    q.push({cX*2,cY*2,0});
    while(!q.empty()){
        int cx,cy,cnt;
        tie(cx,cy,cnt) = q.front();
        q.pop();
        if(cx == iX*2 && cy == iY*2) {
            answer = cnt;
            break;
        }
        for(int i = 0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(visit[nx][ny] || !arr[nx][ny]) continue;
            q.push({nx,ny,cnt + 1});
            visit[nx][ny] = 1;
        }
    }
    return answer / 2;
}