#include <string>
#include <vector>
#include <stack>
using namespace std;

//올바른 괄호 문자열?
bool isCor(string str){
    stack<char>s;
    for(auto x : str){
        if(x == '(') s.push(x);
        else{
            if(!s.empty() && s.top() == '(') s.pop();
            else s.push(x);
        }
    }
    if(s.empty()) return true;
    else return false;
}

string solution(string p) {
    string answer = "";
    // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
    if(p == "") return p;
    int n = p.length();
    string u,v;
    int l = 0, r = 0;
    // 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 
    //단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
    for(int i = 0; i<n; i++){
        u += p[i];
        if(p[i] == '(') l++;
        else r++;
        if(l == r) {
            v = p.substr(i+1);
            break;
        }
    }
    // 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
        //   3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
    if(isCor(u)) return u + solution(v);
    else{
        // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
        //   4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
        //   4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
        //   4-3. ')'를 다시 붙입니다. 
        //   4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
        //   4-5. 생성된 문자열을 반환합니다.
        string tmp = '('+ solution(v) + ')';
        if(u.length() > 0){
            for(int i =1; i<u.length()-1; i++) {
                if(u[i] == '(') tmp +=')';
                else tmp +='(';
            }
        }
        return tmp;
    }
    
    return answer;
}