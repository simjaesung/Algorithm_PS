#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,p,tmp,ans; //사람수 파티수 아는사람수
int arr[55][55];
int know[55],c[55]; //아는사람 memo
vector<vector<int>>party(55);
vector<vector<int>>v(55);
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    cin >> p;
    for(int i = 0; i<p; i++) {
        //아는사람 memo
        cin >> tmp;
        know[tmp] = 1;
    }
    
    for(int i = 0; i<m; i++){
        //파티 참석 정보 저장
        cin >> tmp; //참석하는 사람 수
        for(int k = 0; k < tmp; k++){
            int val; cin >> val;
            party[i].push_back(val);
        }
        
        for(int s = 0; s < tmp; s++){
            for(int j = s + 1; j < tmp; j++){
                arr[party[i][s]][party[i][j]] = 1;
                arr[party[i][j]][party[i][s]] = 1;
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        int check = 0;
        for(auto x : party[i]){
            fill(c,c+55,0);
            queue<int>q;
            q.push(x);
            while(!q.empty()){
                int cx = q.front();
                if(know[cx]) {
                    check = 1;
                    break;
                }
                q.pop();
                c[cx] = 1;
                for(int s = 1; s <= n; s++){
                    if(arr[cx][s] && !c[s]) q.push(s);
                }
            }
            if(check) break;
        }
        if(!check) ans++;
    }
    
    cout << ans;
    
    return 0;
}