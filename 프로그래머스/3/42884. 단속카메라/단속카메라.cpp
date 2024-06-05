#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>a,vector<int>b){
    if(a[1] == b[1]) return a[0] < b[0];
    else return a[1] < b[1];
}
int solution(vector<vector<int>> r) {
    int answer = 1;
    sort(r.begin(), r.end(),compare);
    int val = r[0][1];
    
    for(int i = 1; i<r.size(); i++){
        if(r[i][0] <= val) continue;
        else{
            answer++;
            val = r[i][1];
        }
    }
    return answer;
}