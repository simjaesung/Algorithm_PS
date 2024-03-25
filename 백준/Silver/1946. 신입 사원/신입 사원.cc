#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,a,b;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<pair<int,int>>v;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            v.push_back({a,b});
        }
        sort(v.begin(), v.end());
        
        int ans = 0;
        int minb = v[0].second;
        //서류 순으로 정렬, 
        //면접 성적이 순서상 앞서 나온 성적등수보다 높으면 그사람은 탈락
        
        for(int i = 1; i < n; i++){
            if(v[i].second > minb) ans++;    
            minb = min(minb, v[i].second);
        }
        cout << n - ans <<'\n';
    }
    
    return 0;
}