import java.util.*;

class Solution {
    public List<Integer> solution(int[] progresses, int[] speeds) {
        Deque<Integer> dq = new ArrayDeque<>();
        int n = progresses.length;
        
        for(int i = 0; i < n; i++){
            int remain = 100 - progresses[i];
            if(remain % speeds[i] == 0) dq.add(remain/speeds[i]);
            else dq.add(remain/speeds[i] + 1);
        }
        
        List<Integer> answer = new ArrayList<>();
        
        int front = dq.removeFirst();
        int cnt = 1;
        while(!dq.isEmpty()){
            int tmp = dq.removeFirst();
            if(front >= tmp) cnt++;
            else {
                answer.add(cnt);
                front = tmp;
                cnt = 1;
            }
        }
        answer.add(cnt);
        
        return answer;
    }
}