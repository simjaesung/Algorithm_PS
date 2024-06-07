#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>p, int l) {
    int answer = 0;
    sort(p.begin(), p.end());
    int s = 0, e = p.size()-1;
    while(s <= e){
        if(p[s] + p[e] <= l) {
            s++; e--;
        }
        else e--;
        answer++;
    }
    return answer;
}