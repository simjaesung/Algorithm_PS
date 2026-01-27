import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        List<String> arr = new ArrayList<>();
        for(int num : numbers) arr.add(String.valueOf(num));
        Collections.sort(arr, (a,b) -> {
            return (b+a).compareTo(a+b);
        });
        
        StringBuilder sb = new StringBuilder();
        for(String val : arr) sb.append(val);
        String answer = sb.toString();
        return answer.charAt(0) == '0' ? "0" : answer;
    }
}