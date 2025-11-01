import java.util.*;

class Solution {
    boolean solution(String s) {
        Deque<Character> dq = new ArrayDeque<>();
        
        for(char c : s.toCharArray()){
            if(c == '(') dq.addLast(c);
            else{
                if(!dq.isEmpty() && dq.getLast() == '(') dq.removeLast();
                else return false;
            }
        }
        
        if(!dq.isEmpty()) return false;
        return true;
    }
}