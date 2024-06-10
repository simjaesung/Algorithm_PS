#include<iostream>
#include<algorithm>
using namespace std;
int arr[105][3],s[105],b[105];
int n,ans,val;
int main()
{
    cin >> n;
    fill(s,s+105,-1);
    fill(b,b+105,-1);
    for(int i = 0; i<n; i++){
        cin >> val;
        arr[i][0] = val / 100;
        arr[i][1] = (val % 100) / 10;
        arr[i][2] = val % 10;
        cin >> s[i];
        cin >> b[i];
    }
    
    for(int k = 123; k<=987; k++){
        int a = k / 100;
        int d = (k % 100) / 10;
        int c = k % 10;
        if(a == 0 || d == 0 || c == 0) continue;
        if(a == d || d == c || a == c) continue;
        int check = 1;
        for(int i = 0; i<n; i++){
            int st = 0; int ba = 0;
            if(arr[i][0] == a) st++;
            if(arr[i][1] == d) st++;
            if(arr[i][2] == c) st++;
            if(arr[i][0] == d || arr[i][0] == c) ba++;
            if(arr[i][1] == a || arr[i][1] == c) ba++;
            if(arr[i][2] == a || arr[i][2] == d) ba++;
            
            if(st != s[i] || ba != b[i]) check = 0;
        }
        if(check) ans++;
    }
    cout <<ans;
    return 0;
}