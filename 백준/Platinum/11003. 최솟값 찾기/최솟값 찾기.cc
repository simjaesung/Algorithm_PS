#include<iostream>
#include<queue>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
int n,l,val;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> l;
    for(int i = 0; i<n; i++){
        cin >> val;
        pq.push({val,i});
        if(pq.top().second >= i-l+1) cout << pq.top().first << ' ';
        else{
            while(pq.top().second < i-l+1) pq.pop();
            cout << pq.top().first<< ' ';
        }
    }
    return 0;
}