#include<iostream>
using namespace std;
int p[500005];
int n,m,a,b;

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
    for(int i = 0; i<n; i++) p[i] = i;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        if(find(a) == find(b)){
            cout << i + 1; return 0;
        }
        Union(a,b);
    }
    cout << 0;
    return 0;
}