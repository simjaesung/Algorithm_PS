#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int n; //움직이는 횟수
unordered_map<string,int>m;
string mov[8] = {"R","L","B","T","RT","LT","RB","LB"};
char loc[8] = {'A','B','C','D','E','F','G','H'};
int dx[8] = {0,0,1,-1,-1,-1,1,1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};
string king,rock; 
int kx,ky,rx,ry; //왕과 돌의 위치
int nkx,nky,nrx,nry;

bool inrange(int x, int y){
    return x>=0 && x<8 && y>=0 && y<8;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<8; i++) m[mov[i]] = i;
    //dydx인덱스 접근을 위한 map처리
    cin >> king >> rock >> n;
    kx = 8 - (king[1] - '0');
    ky = tolower(king[0]) - 'a';
    rx = 8 - (rock[1] - '0');
    ry = tolower(rock[0]) - 'a';
    //초기까지는맞음
    
    for(int i = 0; i<n; i++){
        string go; cin >> go;
        nkx = kx + dx[m[go]];
        nky = ky + dy[m[go]];
        if(!inrange(nkx,nky)) continue;
        if(nkx == rx && nky == ry){
            nrx = rx + dx[m[go]];
            nry = ry + dy[m[go]];
            if(!inrange(nrx,nry)) continue;
            rx += dx[m[go]]; ry += dy[m[go]];
        }
        kx = nkx; ky = nky;
    }
    
    cout << loc[ky]<< 8-kx<<'\n';
    cout << loc[ry]<< 8-rx;
}
    