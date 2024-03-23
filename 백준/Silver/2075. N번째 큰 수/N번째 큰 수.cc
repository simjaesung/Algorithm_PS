#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>>pq;
int n, val;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i<n*n; i++){
        cin >> val; 
        if(pq.size() < n) pq.push(val);
        else if(pq.top() < val){
            pq.pop();
            pq.push(val);
        }
        //가장 작은것보다 큰게 들어오면 pop 후 push
    }

    cout << pq.top();
    
    return 0;
}