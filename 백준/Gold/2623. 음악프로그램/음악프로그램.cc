#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int taken[1005]; //화살표받은개수?
vector<int>v[1005];
vector<int>result; //결과 
int n,m,s,tmp;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    
    for(int j = 0; j < m; j++){
        cin >> s;
        vector<int>v_tmp; //pd가 정한 순서 

        for(int k = 0; k < s; k++){
            cin >> tmp;
            v_tmp.push_back(tmp);
        }

        for(int l = 0; l < s-1; l++){
            taken[v_tmp[l+1]]++;
            v[v_tmp[l]].push_back(v_tmp[l+1]);
        }
    }
    
    queue<int>q;
    
    for(int i = 1; i<=n; i++){
        if(!taken[i]) q.push(i);
    }
    
    while(!q.empty()){
        int front = q.front(); q.pop();
        result.push_back(front); 
        for(auto x : v[front]){
            taken[x]--;
            if(!taken[x]) q.push(x);
        }
    }
    
    if(result.size() != n) cout << 0;
    else {
        for(auto x : result) cout << x << '\n';
    }
    
    return 0;
}

