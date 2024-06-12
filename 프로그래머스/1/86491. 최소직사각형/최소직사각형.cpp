#include <string>
#include <vector>

using namespace std;
int a,b; //가로 세로
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    for(auto s : sizes){
        if(s[0] < s[1]){
            a = max(a,s[1]);
            b = max(b,s[0]);
        }
        else{    
            a = max(a,s[0]);
            b = max(b,s[1]);
        }
    }
    
    answer = a * b;
    return answer;
}