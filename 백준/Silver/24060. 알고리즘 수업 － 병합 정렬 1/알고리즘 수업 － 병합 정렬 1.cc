#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,k,val,c,ans = -1;
vector<int>A;
int tmp[500005];

void merge(int s, int m, int e){
    int i = s; int j = m + 1; int t = 0;
    while(i<= m && j <= e){
        if(A[i] <= A[j]) tmp[t++] = A[i++];
        else tmp[t++] = A[j++];
    }
    while(i<=m) tmp[t++] = A[i++];
    while(j<=e) tmp[t++] = A[j++];
    i = s;
    t = 0;
    while(i<=e) {
        c++;
        if(c == k) ans = tmp[t];
        A[i++] = tmp[t++];
    }
}

void merge_sort(int s, int e){
    if(s < e){
        int m = (s + e) / 2;
        merge_sort(s,m);
        merge_sort(m+1,e);
        merge(s,m,e);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        cin >> val;
        A.push_back(val);
    }
    merge_sort(0,n-1);
    cout << ans;
    return 0;
}