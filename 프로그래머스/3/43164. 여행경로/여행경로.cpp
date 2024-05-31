#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int visit[10005];
int sz;
vector<string> answer;

int go(int cnt, string st, vector<vector<string>> tickets){
    if(cnt == sz) return 1;
    for(int i = 0; i<sz; i++){
        if(st == tickets[i][0] && !visit[i]){
            visit[i] = 1;
            answer.push_back(tickets[i][1]);
            if(go(cnt + 1, tickets[i][1],tickets)) return 1;
            visit[i] = 0;
            answer.pop_back();
        }
    }
    return 0;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    sz = tickets.size();
    answer.push_back("ICN");
    go(0,"ICN",tickets);
    return answer;
}