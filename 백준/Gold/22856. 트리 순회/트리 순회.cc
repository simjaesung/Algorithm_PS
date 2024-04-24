#include<iostream>
using namespace std;
int l[100005], r[100005], p[100005], v[100005];
int n,a,b,c,rr,ans;

int findR(int k){
    while(r[k]){
        k = r[k];
    }
    return k;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a >> b >> c;
        if(b != -1){
            l[a] = b;
            p[b] = a;
        }
        if(c != -1){
            r[a] = c;
            p[c] = a;
        }
    }
    rr = findR(1);
    int cur = 1;
    while(1){
        v[cur] = 1;
        ans++;
        if(l[cur] && !v[l[cur]]) cur = l[cur];
        else if(r[cur] && !v[r[cur]]) cur = r[cur];
        else{
            if(cur == rr)break;
            else cur = p[cur];
        }
    }
    cout << ans - 1;
    return 0;
}