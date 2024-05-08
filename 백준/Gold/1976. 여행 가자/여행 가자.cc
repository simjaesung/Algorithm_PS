#include<iostream>
#include<vector>
using namespace std;

int arr[205][205],p[205],t[1005];
int n,m;

int find(int r){
    if(p[r] == r) return r;
    return p[r] = find(p[r]);
}

void Union(int a, int b){
    a = find(a); b = find(b);
    if(a >= b) p[a] = b;
    else p[b] = a;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i<=n; i++) p[i] = i;
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++) {
            cin >> arr[i][j];
            if(arr[i][j]) Union(i,j);
        }
    }
    for(int i = 0; i<m; i++) cin >> t[i];
    for(int i = 0; i<m-1; i++){
        if(find(t[i]) != find(t[i+1])){
            cout << "NO"; return 0;
        }
    }
    cout << "YES";
    return 0;
}