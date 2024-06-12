#include <string>
#include <vector>
#include <cmath>
using namespace std;
int answer;

int isNum(char s){
    char num[10] = {'0','1','2','3','4','5','6','7','8','9'};
    for(int i = 0; i<10; i++){
        if(s == num[i]) return i;
    }
    return -1;
}

int isStrNum(string s){
    string num[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    for(int i = 0; i<10; i++){
        if(num[i] == s) return i;
    }
    return -1;
}

int solution(string s) {
    vector<int>ans;
    string tmp;
    for(int i = 0; i<s.length(); i++){
        if(isStrNum(tmp) != -1){
            ans.push_back(isStrNum(tmp));
            tmp = "";
        }
        if(isNum(s[i]) != -1) ans.push_back(s[i] - '0');
        else tmp += s[i];
    }
    
    if(tmp.length() > 0) ans.push_back(isStrNum(tmp));
    
    
    int k  = ans.size() - 1;
    for(auto x : ans) answer += x*pow(10,k--);
    
    return answer;
}