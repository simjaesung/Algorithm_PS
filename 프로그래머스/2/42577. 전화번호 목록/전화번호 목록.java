import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        Arrays.sort(phone_book);
        Map<String, Boolean> map = new HashMap<>();
        
        for(String num : phone_book){
            int n = num.length();
            for(int i = 0; i < n; i++){
                if(map.containsKey(num.substring(0,i))) return false;
            }
            map.put(num, true);
        }
        return true;
    }
}