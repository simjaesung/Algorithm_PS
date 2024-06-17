#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
int n,l,k;
int r,c,m,s,d,ans;
int c1[4] = {0,2,4,6}; //모두홀짝
int c2[4] = {1,3,5,7}; //아니면
vector<tuple<int,int,int>>arr[55][55];
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

void move(){
    vector<pair<int,int>>v1; //위치정보저장
    vector<tuple<int,int,int>>v2; //다음 파이어볼 상태
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(arr[i][j].size() > 0){
                for(auto x : arr[i][j]){
                    tie(m,s,d) = x; //질량,속도,방향
                    int ns = s % n;
                    int nx = i + dx[d] * ns;
                    int ny = j + dy[d] * ns;
                    if(nx < 1) nx+=n;
                    if(ny < 1) ny+=n;
                    if(nx > n) nx-=n;
                    if(ny > n) ny-=n;
                    v1.push_back({nx,ny});
                    v2.push_back({m,s,d});
                }
                arr[i][j].clear();
            }
        }
    }
    int cnt = v1.size();
    for(int i = 0; i<cnt; i++){
        int x = v1[i].first;
        int y = v1[i].second;
        tie(m,s,d)= v2[i];
        arr[x][y].push_back({m,s,d});
    }
}

int isAll(vector<int>v){
    int nn = v.size();
    int tmp = v[0];
    int res = 1; //1이면 모두 홀수나 짝수인거
    for(int i = 1; i<nn; i++){
        if(tmp % 2 == 0 && v[i] % 2 == 1) res = 0;
        else if(tmp % 2 == 1 && v[i] % 2 == 0) res = 0;
        tmp = v[i];
    }
    return res;
}

void sep(){
    vector<pair<int,int>>v1; //위치정보저장
    vector<tuple<int,int,int>>v2; //다음 파이어볼 상태
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(arr[i][j].size() > 1){
                int sumM = 0; //질량의 합
                int sumS = 0; //속력의 합
                vector<int>checkD; //방향 체크할꺼
                for(auto x : arr[i][j]){
                    tie(m,s,d) = x; //질량,속도,방향
                    sumM += m;
                    sumS += s;
                    checkD.push_back(d);
                }
                sumM /= 5;
                sumS /= arr[i][j].size();
                arr[i][j].clear();
                
                if(sumM > 0){ 
                    if(isAll(checkD)){ //모두 홀수나 짝수
                        for(int u = 0; u<4; u++){
                            v1.push_back({i,j});
                            v2.push_back({sumM, sumS, c1[u]});
                        }
                    }
                    else{
                        for(int u = 0; u<4; u++){
                            v1.push_back({i,j});
                            v2.push_back({sumM,sumS,c2[u]});
                        }
                    }
                }
            }
        }
    }
    
    int cnt = v1.size();
    for(int i = 0; i<cnt; i++){
        int x = v1[i].first;
        int y = v1[i].second;
        tie(m,s,d)= v2[i];
        arr[x][y].push_back({m,s,d});
    }
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> l >> k;
    for(int i = 0; i<l; i++){
        cin >> r >> c >> m >> s >> d;
        arr[r][c].push_back({m,s,d}); //질량,속도,방향
    }
    
    while(k--){
        move();
        sep();
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(arr[i][j].size() > 0){
                for(auto x : arr[i][j]){
                    tie(m,s,d) = x; //질량,속도,방향
                    ans += m;
                }
            }
        }
    }
    cout << ans;
    return 0;
}