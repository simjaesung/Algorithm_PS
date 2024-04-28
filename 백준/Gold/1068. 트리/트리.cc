#include<iostream>
#include<vector>
using namespace std;
int n,val,del,ans;
int p[55];
vector<int> c[55];

void sol(int r)
{
    if(!c[r].size()){
        ans++;
        return;
    }
    for(int i = 0; i<c[r].size(); i++) sol(c[r][i]);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> val;
        p[i] = val;
        if(val != -1) c[val].push_back(i);
    }
    cin >> del;
    if(p[del] == -1){
        cout << 0; 
        return 0;
    }
    
    //부모노드에서 삭제시키기
    int tmp = -1;
    for(int i = 0; i<c[p[del]].size(); i++){
        if(c[p[del]][i] == del) tmp = i;
    }
    if(tmp != -1) c[p[del]].erase(c[p[del]].begin()+tmp);
    
    //루트찾기
    int root = -1;
    for(int i = 0; i<n; i++){
        if(p[i] == -1) root = i;
    }
    sol(root);
    
    cout << ans;
    return 0;
}