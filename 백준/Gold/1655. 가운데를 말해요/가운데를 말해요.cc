#include<iostream>
#include<queue>
using namespace std;

priority_queue<int,vector<int>> lpq;
priority_queue<int,vector<int>,greater<int>> rpq;
int n,val;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(n--){
        cin >> val;
        if(lpq.size() <= rpq.size()) lpq.push(val);
        else rpq.push(val);
        
       
        if(!rpq.empty() && rpq.top() < lpq.top()){
            lpq.push(rpq.top());
            rpq.push(lpq.top());
            //swap
            rpq.pop(); lpq.pop();
        }
        
        cout << lpq.top() << '\n';
        
    }
    return 0;
}