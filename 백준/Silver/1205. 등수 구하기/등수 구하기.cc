#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,p,ans = -1; 
vector<int>v;
bool comp(int a, int b){
    return b < a;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> p;
    //스코어에 기재될 수 / 점수 / 등록되어있는 점수개수
    while(n--){
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    v.push_back(k);
    
    sort(v.begin(),v.end(),comp);
    int tmp = 0;
    for(int i = 0; i<v.size(); i++){
        if(v[i] == k) {
            ans = i+1;
            tmp++;
        }
    }
    if(ans > p) cout << -1;
    else cout << ans - (tmp-1);
    return 0;
}