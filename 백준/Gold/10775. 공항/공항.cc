#include<iostream>
using namespace std;
int p[100005];
int g,k,val,ans;
int find(int r)
{
    if(p[r] == r) return r;
    else return p[r] = find(p[r]);
}

void join(int a, int b)
{
    a = find(a); b = find(b);
    if(a >= b) p[a] = b;
    else p[b] = a;
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> g >> k;
    for(int i = 1; i<=g; i++) p[i] = i;
    
    for(int i = 0; i<k; i++){
        cin >> val;
        if(find(val) != 0){
            ans++;
            join(find(val),find(val)-1);
        }
        else break;
    }
    cout << ans;
    return 0;
}