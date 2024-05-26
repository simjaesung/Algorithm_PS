#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    int answer = 0;
    int i = 0;
    int cnt = 0; //연속된 일의 시간을 확인
    
    sort(jobs.begin(),jobs.end());
    
    while(i < jobs.size() || !pq.empty()){
        if(i < jobs.size() && jobs[i][0] <= cnt){
            pq.push({jobs[i][1],jobs[i][0]});
            i++;
            continue;
        }
        if(!pq.empty()){
            cnt += pq.top().first;
            answer += cnt - pq.top().second;
            pq.pop();
        }
        else cnt = jobs[i][0];
    }
    answer /= jobs.size();
    
    return answer;
}