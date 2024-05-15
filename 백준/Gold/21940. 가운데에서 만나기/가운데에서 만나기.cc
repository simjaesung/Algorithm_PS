#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int inf = 0x3f3f3f3f;
int live[205], r[205][205];
int n,m,a,b,t,k,c,ans = inf;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        fill(r[i] + 1, r[i] + n + 1, inf);
        r[i][i] = 0;
    }
    
    for(int i = 0; i<m; i++){
        cin >> a >> b >> t;
        r[a][b] = min(r[a][b],t);
    }
    
    for(int s = 1; s<=n; s++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                r[i][j] = min(r[i][j], r[i][s] + r[s][j]);
            }
        }
    }
    
    cin >> k;
    for(int i = 1; i<=k; i++) cin >> live[i]; //사는 도시
    vector<pair<int,int>>v;
    int ans_tmp = inf;
    for(int i = 1; i<=n; i++){
        int checkinf = 0;
        int tmp = 0;
        for(int j = 1; j<=k; j++) {
            if(r[i][live[j]] == inf || r[live[j]][i] == inf) {
                checkinf = 1;
                break;
            }
            tmp = max(tmp, r[i][live[j]] + r[live[j]][i]);
        }
        if(checkinf) continue;
        ans_tmp = min(ans_tmp, tmp); // 친구들 개개인 왕복시간의 최대값 중 전체 최소값;;
        v.push_back({i,tmp});
    }
    sort(v.begin(),v.end());
    for(auto x : v){
        if(x.second == ans_tmp) cout << x.first << ' ';
    }
    
    return 0;
}