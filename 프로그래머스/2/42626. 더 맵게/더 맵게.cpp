#include <string>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    for(auto x : scoville) pq.push(x);
    
    while(pq.size() > 1 && pq.top() < K){
        answer++;
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ll mix = a + 2 * b;
        pq.push(mix);
    }
    if(pq.top() >= K) return answer;
    else return -1;
}