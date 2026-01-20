import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Map<String, Integer> m = new HashMap<>();
        for(String c : completion){
            m.put(c, m.getOrDefault(c, 0) + 1);
        }
        
        for(String p: participant){
            if(!m.containsKey(p) || m.get(p) == 0){
                answer = p;
                break;
            } else m.put(p, m.get(p) - 1);
        }
    
        return answer;
    }
}