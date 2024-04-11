#include<iostream> 
#include<map>
using namespace std;

int n,ans;
map<string,int>m;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while(n--){
        string cmd;
        cin >> cmd;
        if(cmd == "ENTER") m.clear();
        else{
            if(!m[cmd]) {
                m[cmd] = 1;
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}