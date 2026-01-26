import java.util.*;

class Solution {
    public List<Integer> solution(int[] array, int[][] commands) {
        List<Integer> answer = new ArrayList<>();
        for(int[] command : commands){
            int i = command[0];
            int j = command[1];
            int k = command[2];
            int[] sliced = Arrays.copyOfRange(array,i-1,j);
            Arrays.sort(sliced);
            answer.add(sliced[k-1]);
        }
        
        return answer;
    }
}