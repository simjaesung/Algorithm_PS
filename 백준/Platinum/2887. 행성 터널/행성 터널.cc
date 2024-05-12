#include<iostream>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;

int p[100005];
int n,a,b,c;
long long ans;
vector<pair<int,int>>x;
vector<pair<int,int>>y;
vector<pair<int,int>>z;
vector<tuple<int,int,int>>v;

int find(int r){
    if(p[r] == r) return r;
    else return p[r] = find(p[r]);
}

void merge(int a, int b){
    a = find(a); b = find(b);
    if(a >= b) p[a] = b;
    else p[b] = a;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++) p[i] = i;
    for(int i = 1; i<=n; i++){
        cin >> a >> b >> c;
        x.push_back({a,i});
        y.push_back({b,i});
        z.push_back({c,i});
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    
    for(int i = 0; i<n-1; i++){
        v.push_back({abs(x[i].X - x[i+1].X),x[i].Y,x[i+1].Y});
        v.push_back({abs(y[i].X - y[i+1].X),y[i].Y,y[i+1].Y});
        v.push_back({abs(z[i].X - z[i+1].X),z[i].Y,z[i+1].Y});
    }
    
    sort(v.begin(), v.end());
    
    int cnt = 0;
    for(auto s : v){
        tie(a,b,c) = s;
        if(find(b) == find(c)) continue;
        merge(b,c);
        ans += a;
        cnt++;
        if(cnt == n-1) break;
    }
    cout << ans;
    return 0;
}