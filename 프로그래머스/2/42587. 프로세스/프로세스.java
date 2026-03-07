import java.util.*;

class Solution {
    static class Pair{
        int val; int idx;
        public Pair(int val, int idx){
            this.val = val; this.idx = idx;
        }
    }
    
    public int solution(int[] priorities, int location) {
        int n = priorities.length;
        Deque<Pair> dq = new ArrayDeque<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b-a);
        for(int i = 0; i < n; i++){
            dq.addLast(new Pair(priorities[i], i));
            pq.add(priorities[i]);
        }
        
        int answer = 0;
        while(!dq.isEmpty()){
            Pair cur = dq.removeFirst();
            if(cur.val == pq.peek()){
                pq.poll();
                answer++;
                if(cur.idx == location) break;
            }
            dq.addLast(cur);
        }
        return answer;
    }
}