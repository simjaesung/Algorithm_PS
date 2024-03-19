#include<iostream>
#include<set>
using namespace std;
int n,t,val;
string cmd;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        
        multiset<int>s;
        s.clear();
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> cmd >> val; 
            
            if(cmd == "I") s.insert(val);
            else if (cmd == "D"){
                if(s.empty()) continue;
                
                if(val == 1) {
                    auto iter = s.end();
                    iter--;
                    s.erase(iter);
                }
                else {
                    auto iter = s.begin();
                    s.erase(iter);
                }
            }
        }
        
        if(s.empty()) cout << "EMPTY\n";
        else {
            auto iter1 = s.end();
            iter1--;
            auto iter2 = s.begin();
            cout << *iter1 << ' ' << *iter2 << '\n';
        }
    }
    
    return 0;
}