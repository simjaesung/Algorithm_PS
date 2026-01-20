import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        Deque<Integer> dq = new ArrayDeque<>();
        for(int val : arr){
            if(dq.isEmpty() || dq.getLast() != val){
                dq.addLast(val);
            }
        }
        
        int[] answer = new int[dq.size()];
        int i = 0;
        while(!dq.isEmpty()){
            answer[i++] = dq.removeFirst();
        }

        return answer;
    }
}