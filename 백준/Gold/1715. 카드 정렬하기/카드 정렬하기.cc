#include<iostream>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,greater<int>>pq;
int n, val, ans;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(n--){
        cin >> val;
        pq.push(val);
    }
    
    while(pq.size() > 1){
        int tmp = 0;
        
        tmp += pq.top();
        pq.pop();
        
        if(pq.empty()) break;
        
        tmp += pq.top();
        pq.pop();
        
        ans += tmp;
        pq.push(tmp);
    }
    
    cout << ans;
    return 0;
}