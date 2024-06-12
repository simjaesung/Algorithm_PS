#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int open[105];
int g1,g2;

int solution(vector<int> cards) {
    int answer = 0;
    int n = cards.size();
    
    for(int i = 0; i<n; i++){
        fill(open,open+105,0);
        g1 = 0;
        int k1 = i; //1라운드 임의의 상자
        
        while(1){
            open[k1] = 1;
            g1++;
            k1 = cards[k1]-1;
            if(open[k1]) break;
        }
        
        for(int j = 0; j<n; j++){
            if(open[j]) continue; //1라운드에서 연거
            g2 = 0;
            int tmpOpen[105] = {0,}; //2라운드
            for(int l = 0; l<n; l++) 
                tmpOpen[l] = open[l]; //1라운드의 배열을 복사
            
            int k2 = j; //2라운드 임의의 상자
            
            while(1){
                tmpOpen[k2] = 1;
                g2++;
                k2 = cards[k2]-1;
                if(tmpOpen[k2]) break;
            }
            answer = max(answer, g1 * g2);
        }
    }
    return answer;
}