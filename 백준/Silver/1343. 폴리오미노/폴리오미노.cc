#include<iostream>
using namespace std;
string s,ans;
int cnt;
int main()
{
    cin >> s;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == 'X') cnt++;
        else{
            if(cnt % 2 == 1){
                cout << -1;
                return 0;
            }
            else{ 
                if(cnt > 0){
                    while(cnt > 2){
                        ans += "AAAA";
                        cnt-=4;
                    }
                    if(cnt != 0){
                        ans += "BB";
                        cnt = 0;
                    }
                }
            }
            ans += s[i];
        }
    }
    if(cnt % 2){
        cout << -1; 
        return 0;
    }
    else{
        while(cnt > 2){
            ans += "AAAA";
            cnt-=4;
        }
        if(cnt != 0){
            ans += "BB";
            cnt = 0;
        }
    }
    cout << ans;
    return 0;
}