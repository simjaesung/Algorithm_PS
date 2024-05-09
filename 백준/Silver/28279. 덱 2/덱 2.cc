#include<iostream>
#include<deque>
using namespace std;
int n,cmd,val;
deque<int>dq;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(n--){
        cin >> cmd;
        if(cmd == 1){
            cin >> val;
            dq.push_front(val);
        }
        else if(cmd ==2){
            cin >> val;
            dq.push_back(val);
        }
        else if(cmd ==3){
            if(dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            
        }
        else if(cmd ==4){
            if(dq.empty()) cout << -1 << '\n';
            else{
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if(cmd ==5){
            cout << dq.size() << '\n';
        }
        else if(cmd ==6){
            if(dq.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(cmd ==7){
            if(!dq.empty()) cout << dq.front() << '\n';
            else cout << -1 << '\n';
        }
        else{
            if(!dq.empty()) cout << dq.back() << '\n';
            else cout << -1 << '\n';
        }
    }
    return 0;
}