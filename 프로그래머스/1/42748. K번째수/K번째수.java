import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        int idx = 0;
        for(int[] command : commands){
            int i = command[0];
            int j = command[1];
            int k = command[2];
            
            ArrayList<Integer> tmp = new ArrayList<>();
            for(int s = i - 1; s < j; s++) tmp.add(array[s]);
            Collections.sort(tmp);
            answer[idx++] = tmp.get(k-1);
        }
        return answer;
    }
}