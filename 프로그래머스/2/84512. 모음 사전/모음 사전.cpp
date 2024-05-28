#include <string>
#include <vector>

using namespace std;
string s = "AEIOU";
int ans;
int cnt = -1;

void dfs(string k, string word){
    cnt++;
    if(k == word) {
        ans = cnt;
        return;
    }
    if(k.length() >= 5) return;
    
    for(int i = 0; i<5; i++){
        dfs(k + s[i], word);
    }
}

int solution(string word) {
    dfs("",word);
    
    return ans;
}