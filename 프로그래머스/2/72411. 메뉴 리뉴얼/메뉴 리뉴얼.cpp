#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string,int>m;
vector<string> answer;
void go(string s, string tmp, int k){
    if(k == s.length()) return;
    for(int i = k; i<s.length(); i++){
        tmp += s[i];
        m[tmp] += 1;
        go(s,tmp,i+1);
        tmp.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for(auto x : orders) {
        sort(x.begin(),x.end());
        go(x,"",0);
    }
    for(int i = 0; i<course.size(); i++){
        int tmp = 0;
        for(auto itr : m){
            if(itr.first.length() == course[i]){
                if(itr.second > tmp) tmp = itr.second;
            }
        }
        
        for(auto itr : m){
            if(itr.first.length() == course[i] && itr.second == tmp){
                if(tmp > 1) answer.push_back(itr.first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}