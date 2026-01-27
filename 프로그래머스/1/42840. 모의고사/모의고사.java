import java.util.*;
class Solution {
    public List<Integer> solution(int[] answers) {
        int[] p1 = {1, 2, 3, 4, 5};
        int[] p2 = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        
        int n = answers.length;
        int p1_answer = 0;
        int p2_answer = 0;
        int p3_answer = 0;

        for(int i = 0; i < n; i++){
            if(p1[i % 5] == answers[i]) p1_answer++;
            if(p2[i % 8] == answers[i]) p2_answer++;
            if(p3[i % 10] == answers[i]) p3_answer++;
        }
        List<Integer> answer = new ArrayList<>();
        int maxP = Math.max(p1_answer, Math.max(p2_answer,p3_answer));
        if(p1_answer == maxP) answer.add(1);
        if(p2_answer == maxP) answer.add(2);
        if(p3_answer == maxP) answer.add(3);
        return answer;
    }
}