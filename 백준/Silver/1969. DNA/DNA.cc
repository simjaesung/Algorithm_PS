#include<iostream>
#include<vector>
#include<limits.h>
#include<map>
using namespace std;
map<char,int>cm;
int n,m;
vector<string>v;
string s,ans1;
int ans2;

char dna[4] = {'A','C','G','T'};
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    for(int i = 0; i<4; i++) cm[dna[i]] = i;
    
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        cin >> s; v.push_back(s);
    }
    
    for(int i = 0; i<m; i++){
        int arr[4] = {0,};
        for(int k = 0; k<n; k++){
            int idx = cm[v[k][i]];
            arr[idx]++;
        }
        char tmp1 = 'A';
        int tmp2 = arr[0];
        for(int s = 1; s < 4; s++){
            if(arr[s] > tmp2){
                tmp1 = dna[s];
                tmp2 = arr[s];
            }
        }
        ans1 += tmp1;
    }
    
    cout << ans1 << '\n';
    
    for(int i = 0; i<n; i++){
        for(int k = 0; k<m; k++){
            if(ans1[k] != v[i][k]) ans2++;
        }
    }
    
    cout << ans2;
    
    return 0;
}