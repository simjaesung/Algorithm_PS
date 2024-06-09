#include <string>
#include <vector>
using namespace std;
int dp[1000005][2]; 
//dp[i][0] 은 첫번째 집을 지었을떄 최대
//dp[i][1] 은 첫번째 집을 안지었을 때 최대
int answer;

int solution(vector<int> money) {
    int sz = money.size();
    dp[0][0] = money[0];
    dp[1][1] = money[1];
    dp[2][0] = dp[0][0] + money[2];
    dp[2][1] = money[2];
    
    for(int i = 3; i<sz; i++){
        dp[i][0] = max(dp[i-2][0], dp[i-3][0]) + money[i];
        dp[i][1] = max(dp[i-2][1], dp[i-3][1]) + money[i];
    }
    
    for(int i = 0; i<money.size()-1; i++){
        answer = max(max(dp[i][0],dp[i][1]),answer);
    }
    
    answer = max(dp[sz-1][1],answer);
    return answer;
}