#include<iostream>
#include<vector>
using namespace std;
int n,t;
char oper[3] = {' ', '+', '-'};
vector<char>save_oper;

int cal(string s){
    vector<int>num;
    vector<char>pm;
    
    int tmp = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ') continue;
        if(s[i] == '+' || s[i] == '-') {
            pm.push_back(s[i]);
            num.push_back(tmp);
            tmp = 0;
        }
        else{
            tmp *= 10;
            tmp += s[i] - '0';
        }
    }
    num.push_back(tmp);
    
    int result = num[0];
    int idx = 0;
    for(int i = 1; i<num.size(); i++){
        if(pm[idx] == '-') result -= num[i];
        else result += num[i];
        idx++;
    }
    return result;
}

void go(int cnt)
{
    if(cnt == n-1){
        string tmp;
        
        int idx = 0;
        for(int i = 1; i<=n; i++){
            tmp += to_string(i);
            if(idx < n - 1) tmp += save_oper[idx++];
        }
        if(cal(tmp) == 0) cout << tmp << '\n';
        return;
    }
    for(auto x : oper){
        save_oper.push_back(x);
        go(cnt + 1);
        save_oper.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        go(0);
        cout << '\n';
    }
    return 0;
}