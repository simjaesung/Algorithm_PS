#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int k,l; //수강가능인원,클릭인원
vector<string>arr;
unordered_map<string,int>m;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> k >> l;
    for(int i = 0; i<l; i++) {
        string s; cin >> s;
        arr.push_back(s);
        m[s]++;
    }
    
    int cnt = 0; //현재 수강신청성공 인원
    for(auto x : arr){
        if(m[x] == 1) {
            cout << x << '\n';
            cnt++;
            if(cnt == k) break;
        }
        else m[x]--;
    }
    
    return 0;
}
    