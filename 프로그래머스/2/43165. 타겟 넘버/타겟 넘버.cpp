#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<pair<int,int>>q;
    q.push({numbers[0],1});
    q.push({numbers[0] * -1,1});
    while(!q.empty()){
        int nx = q.front().first;
        int s = q.front().second;
        q.pop();
        if(s == numbers.size()){
            if(nx == target) answer++;
            continue;
        }
        q.push({nx + numbers[s], s + 1});
        q.push({nx - numbers[s], s + 1});
    }
    return answer;
}