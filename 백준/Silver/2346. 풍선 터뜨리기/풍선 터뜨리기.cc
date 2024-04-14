#include<iostream>
#include<deque>
using namespace std;
int n,paper,p[1005];
deque<int>dq;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        dq.push_back(i);
        cin >> paper;
        p[i] = paper;
    }
    
    while(!dq.empty()){
        cout << dq.front() << ' ';
        int cmd = p[dq.front()];
        dq.pop_front();
        
        if(cmd > 0){
            cmd--;
            while(cmd--){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            cmd = -cmd;
            while(cmd--){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    return 0;
}