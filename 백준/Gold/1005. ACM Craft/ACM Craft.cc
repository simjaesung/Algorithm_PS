#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,m,k,a,b,last;
int tim[1005]; //건물 짓는데 걸리는 시간
int c[1005]; //선행건물 개수
vector<int>p[1005]; //선행 관계

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        fill(tim,tim+1005,0);
        fill(c,c+1005,0);
        for(int i = 1; i<=n; i++) p[i].clear();
        
        for(int i = 1; i<=n; i++){
            cin >> k; tim[i] = k;
        }
        
        for(int i = 0; i<m; i++){
            cin >> a >> b;
            p[a].push_back(b);
            c[b]++;
        }
        cin >> last;
        
        int ans = 0;
        queue<int>q;
        
        for(int i = 1; i<=n; i++){
            if(!c[i]) q.push(i);
        }
        
        while(!q.empty()){
            int sz = q.size();
            int check = 0; // 마지막 건물이 나왔는지 체크
            int timetmp = 0; //0시간 체크
            for(int i = 0; i<sz; i++){
                int tmp = q.front();
                q.pop();
                if(tim[tmp]) timetmp++;
                tim[tmp]--;
                q.push(tmp);
            }
            
            //짓는 시간이 0시간인 건물이 존재할 경우 다른 건물들의 시간 복구
            if(timetmp / sz < 1){
                for(int i = 0; i<sz; i++){
                    int tmp = q.front();
                    q.pop();
                    if(!tim[tmp]) tim[tmp]++;
                    q.push(tmp);
                }
            }
            else ans++;
            
            for(int i = 0; i<sz; i++){
                int tmp = q.front();
                q.pop();
                if(tim[tmp] <= 0){
                    if(tmp == last) {
                        check = 1;
                        break;
                    }
                    for(auto x : p[tmp]){
                        c[x]--;
                        if(!c[x]) q.push(x);
                    }
                }
                else q.push(tmp);
            }
            if(check) break;
        }
        cout << ans <<'\n';
    }
    return 0;
}
