#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int arr[205][205];
int r,c,n; //arr[r][c], 초
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool inrange(int x, int y){
    return x > 0 && x <=r && y > 0 && y <=c;
}

void input(){
    int cnt = 0; //폭탄 설치 개수 
    cin >> r >> c >> n;
    for(int i = 1; i<=r; i++){
        string s; cin >> s;
        for(int j = 0; j<c; j++) {
            if(s[j] == 'O') arr[i][j+1] = 1; 
            else arr[i][j+1] = -1;
        }
    }
}

void output(){
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            if(arr[i][j] == -1) cout << '.';
            else cout << 'O';
        }
        cout << '\n';
    }
}

void bomb(){
    vector<pair<int,int>>tmp;
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            if(arr[i][j] == 0){
                tmp.push_back({i,j});
                for(int k = 0; k<4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(inrange(nx,ny)) tmp.push_back({nx,ny});
                }
            }
        }
    }
    for(auto x : tmp) arr[x.first][x.second] = -1;
}

void drop(){
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            if(arr[i][j] == -1) arr[i][j] = 3;
        }
    }
}

void time(){
    for(int i = 1; i<=r; i++){
        for(int j = 1; j<=c; j++){
            if(arr[i][j] > 0) arr[i][j]--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    input();
    int t = 2; //1초후는 동일
    while(t<=n){
        if(t % 2 == 1) bomb();
        else drop();
        time();
        t++;
    }
    output();
    return 0;
}