#include <string>
#include <vector>
using namespace std;
vector<int>dp[10]; 

int solution(int n, int num) {
    int answer = -1;
    int tmp = 0;
    for(int i = 1; i<=8; i++){
        tmp = (tmp * 10) + n;
        dp[i].push_back(tmp);
    }
    
    for(int i = 2; i<=8; i++){
        for(int j = 1; j <= i; j++){
            for(auto s : dp[j]){
                for(auto k : dp[i-j]){
                    dp[i].push_back(s + k);
                    dp[i].push_back(s - k);
                    if(k != 0) dp[i].push_back(s / k);
                    dp[i].push_back(s * k);
                }
            }
        }
    }
    for(int i = 1; i<=8; i++) {
        int check = 0;
        for(auto x : dp[i]){
            if(x == num) check = 1;
        }
        if(check) {
            answer = i; 
            break;
        }
    }
    return answer;
}