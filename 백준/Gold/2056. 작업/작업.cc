#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n,m,k,val,ans;
vector<int>p[10005]; //다음작업
int c[10005]; //선행작업갯수
int t[10005]; //작업 시간
queue<int>q;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> m >> k;
        t[i] = m; c[i] = k;
        for(int j = 0; j<k; j++){
            cin >> val;
            p[val].push_back(i);
        }
    }
    
    for(int i = 1; i<=n; i++){
        if(!c[i]) q.push(i);
    }
    
    while(!q.empty()){
        int sz = q.size();
        
        for(int i = 0; i<sz; i++){
            int tmp = q.front();
            q.pop();
            t[tmp]--;
            q.push(tmp);
        }
        ans++;
        for(int i = 0; i<sz; i++){
            int tmp = q.front();
            q.pop();
            if(t[tmp] == 0){
                for(auto x : p[tmp]){
                    c[x]--;
                    if(!c[x]) q.push(x);
                }
            }
            else q.push(tmp);
        }
    }
    
    cout << ans;
    return 0;
}