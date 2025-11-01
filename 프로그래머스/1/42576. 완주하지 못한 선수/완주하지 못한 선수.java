import java.util.*;

class Solution {
    public Map<String,Integer> map = new HashMap<>();
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        for(String s : completion) map.put(s, map.getOrDefault(s, 0) + 1); 
        
        for(String s : participant) {
            if(!map.containsKey(s) || map.get(s) == 0) {
                answer = s;
                break;
            }
            map.put(s, map.get(s) - 1); 
        }
        return answer;
    }
}