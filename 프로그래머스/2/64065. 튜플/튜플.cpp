#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int cntNum[100005];
bool cmp(pair<int,int>a, pair<int,int>b){
    if(a.first < b.first) return b < a;
}
vector<pair<int,int>>v;

vector<int> solution(string s) {
    vector<int> answer;
    string num;
    for(int i = 0; i<s.length(); i++){
        if(s[i] != '{' && s[i] != '}' && s[i] != ',') num += s[i];
        else{
            if(num.length() > 0) {
                int k = stoi(num);
                cntNum[k]++;
            }
            num="";
        }
    }
    
    for(int i = 1; i<=100000; i++){
        if(cntNum[i] > 0) v.push_back({cntNum[i],i});
    }
    
    sort(v.begin(),v.end(),cmp);
    for(auto x : v) answer.push_back(x.second);
    
    return answer;
}