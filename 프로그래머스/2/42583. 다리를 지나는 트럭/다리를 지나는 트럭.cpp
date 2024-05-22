#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int ans = 0;
    int w_truck = 0;
    int idx = 0;
    queue<int>q;
    
    while(idx < truck_weights.size()){
        
        if(q.size() == bridge_length){
            w_truck -= q.front();
            q.pop();
        }
        
        if(w_truck + truck_weights[idx] <= weight){
            q.push(truck_weights[idx]);
            w_truck += truck_weights[idx++];
        }
        else q.push(0);
        
        ans++;
    }
    
    ans += bridge_length;
    
    return ans;
}