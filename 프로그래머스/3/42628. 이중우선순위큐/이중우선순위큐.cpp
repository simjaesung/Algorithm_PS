#include <string>
#include <vector>
#include<queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int cnt = 0;
    int len = operations.size();
    priority_queue<int,vector<int>, greater<int>>min_pq;
    priority_queue<int>max_pq;

    for(int i = 0; i<len; i++){
        if(operations[i][0] == 'I'){
            string tmp = operations[i].substr(2);
            int k = stoi(tmp);
            min_pq.push(k);
            max_pq.push(k);
            cnt++;
        }
        else{
            if(cnt == 0) continue;
            if(cnt == 1){
                while(!min_pq.empty())min_pq.pop();
                while(!max_pq.empty())max_pq.pop();
                cnt--;
                continue;
            }
            if(operations[i][2] == '-') min_pq.pop();
            else max_pq.pop();
            cnt--;
        }
    }
    
    if(cnt > 0){
        answer.push_back(max_pq.top());
        answer.push_back(min_pq.top());
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}