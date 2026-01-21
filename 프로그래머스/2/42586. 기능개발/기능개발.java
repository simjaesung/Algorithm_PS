import java.util.*;

class Solution {
    public List<Integer> solution(int[] progresses, int[] speeds) {
        List<Integer> answer = new ArrayList<>();
        int n = progresses.length;
        
        int day = 1; int cnt = 0;
        for(int i = 0; i < n; i++){
            int remain = 100 - (progresses[i] + day * speeds[i]);
            if(remain > 0) {
                if(cnt > 0) {
                    answer.add(cnt);
                    cnt = 0;
                }
                if(remain % speeds[i] == 0){
                    day += remain / speeds[i];
                }else day += remain / speeds[i] + 1;
                
                cnt++;
            } else cnt++;
        }
        if(cnt > 0) answer.add(cnt);
        return answer;
    }
}