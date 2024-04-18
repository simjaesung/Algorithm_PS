#include<iostream>
#include<queue>
using namespace std;
int n,dasom,val,ans;
priority_queue<int>pq;

int main() {
    cin >> n;
    for(int i = 0; i<n; i++){
        if(i == 0) cin >> dasom;
        else{
            cin >> val;
            pq.push(val);
        }
    }
    
    while(!pq.empty() && pq.top() >= dasom){
        int tmp = pq.top();
        pq.pop();
        if(tmp > 0){
            tmp--;
            dasom++;   
            ans++;
            pq.push(tmp);
        }
    }
    
    cout << ans;
	return 0;
}