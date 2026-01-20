import java.util.*;

public class Solution {
    public Deque<Integer> solution(int []arr) {
        Deque<Integer> dq = new ArrayDeque<>();
        for(int val : arr){
            if(dq.isEmpty() || dq.getLast() != val){
                dq.addLast(val);
            }
        }

        return dq;
    }
}