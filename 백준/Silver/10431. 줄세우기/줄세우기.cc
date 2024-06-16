#include<iostream>
#include<stack>
using namespace std;
int t,h,cnt;//테스트케이스, 키
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int i = 1; i<=t; i++){
        cin >> cnt;
        int ans = 0;
        stack<int>s;
        for(int k = 0; k<20; k++){
            cin >> h;
            if(s.empty()) s.push(h);
            else if(s.top() < h) s.push(h);
            else{
                stack<int>tmp;
                while(!s.empty() && s.top() > h){
                    tmp.push(s.top());
                    s.pop();
                }
                s.push(h);
                ans += tmp.size();
                while(!tmp.empty()){
                    s.push(tmp.top());
                    tmp.pop();
                }
            }
        }
        cout << cnt << ' ' << ans << '\n';
    }
    
    return 0;
}