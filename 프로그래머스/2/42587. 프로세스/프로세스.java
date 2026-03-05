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
        Deque<Integer> pri = new ArrayDeque<>();
        
        for(int i = 0; i < n; i++) dq.add(new Pair(priorities[i], i));
        Arrays.sort(priorities);
        for(int i = n-1; i >=0; i--) pri.add(priorities[i]);
        
        int answer = 0;
        while(!dq.isEmpty()){
            Pair cur = dq.removeFirst();
            if(cur.val == pri.getFirst()){
                answer++;
                if(cur.idx == location) break;
                pri.removeFirst();
            }
            dq.addLast(cur);
        }
        
        return answer;
    }
}