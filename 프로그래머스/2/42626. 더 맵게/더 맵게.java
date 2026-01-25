import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for(int scov : scoville) pq.add((long)scov);
        while(pq.peek() < K && pq.size() > 1){
            long a = pq.poll();
            long b = pq.poll() * 2;
            pq.add(a + b);
            answer++;
        }
        if(pq.peek() < K) return -1;
        return answer;
    }
}