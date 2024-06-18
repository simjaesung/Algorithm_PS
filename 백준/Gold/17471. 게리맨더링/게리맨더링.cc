#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int visit[15]; //방문
int sep[15]; //분류
int cost[15]; //비용
int c[15],tmp[15]; //순열돌릴꺼 
vector<int>adj[15];
int n,val,Ast,Bst;
int ans = 0x3f3f3f3f;

void input(){
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> cost[i];
    for(int i = 1; i<=n; i++){
        int t; cin >> t;
        while(t--){
            cin >> val;
            adj[i].push_back(val);
            adj[val].push_back(i);
        }
    }
}

//sep이 1
void CycleA(int x){
    queue<int>q;
    q.push(x); visit[x] = 1;
    while(!q.empty()){
        int cx = q.front();
        q.pop();
        for(auto nx : adj[cx]){
            if(visit[nx] || sep[nx] != 1) continue;
            q.push(nx);
            visit[nx] = 1;
        }
    }
}

//sep이 2
void CycleB(int x){
    queue<int>q;
    q.push(x); visit[x] = 1;
    while(!q.empty()){
        int cx = q.front();
        q.pop();
        for(auto nx : adj[cx]){
            if(visit[nx] || sep[nx] != 2) continue;
            q.push(nx);
            visit[nx] = 1;
        }
    }
}

//모두 방문했는지?
int isAll(){
    int check = 1;
    for(int i = 1; i<=n; i++){
        if(!visit[i]) check = 0;
    }
    return check;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    input();
    
    for(int i = 1; i<n; i++){
        c[i] = 1;
        for(int k = 1; k<=n; k++) tmp[k] = c[k];//복사
        
        do{
            fill(visit,visit+n+1,0);
            for(int l = 1; l<=n; l++){
                if(tmp[l]) {
                    sep[l] = 1;
                    Ast = l;
                }
                else {
                    sep[l] = 2;
                    Bst = l;
                }
            }
            
            CycleA(Ast);
            CycleB(Bst);
            
            
            if(isAll()){
                int Acost = 0, Bcost = 0;
                for(int j = 1; j<=n; j++){
                    if(sep[j] == 1) Acost += cost[j];
                    else Bcost += cost[j];
                }
                ans = min(ans,abs(Acost - Bcost));
            }
            
        }while(prev_permutation(tmp+1, tmp+n+1));
    }
    
    if(ans == 0x3f3f3f3f) cout << -1;
    else cout << ans;
    return 0;
}