#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int n,arr[1050];
vector<int>v[15];

void tree(int s, int e, int dep){
   if(s >= e) return;
    int m = (s + e) / 2;
    v[dep].push_back(arr[m]);
    tree(s, m, dep + 1);
    tree(m+1, e, dep + 1);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i<pow(2,n); i++) cin >> arr[i];
    tree(0, pow(2,n)-1, 0);
    
    for(int i = 0; i<n; i++){
        for(auto x : v[i]) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}