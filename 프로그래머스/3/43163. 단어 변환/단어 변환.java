import java.util.*;

class Solution {
    static class Pair{
        String s; int cnt;
        public Pair(String s, int cnt){
            this.s = s; this.cnt = cnt;
        }
    }
    
    public boolean checkOne(String a, String b){
        int cnt = 0;
        for(int i = 0; i < a.length(); i++) {
            if(a.charAt(i) != b.charAt(i)) cnt++;
        }
        return cnt == 1;
    }
    
    public int solution(String begin, String target, String[] words) {
        int n = words.length;
        int stringLen = begin.length();
        
        boolean[] isUsed = new boolean[n];
        Deque<Pair> dq = new ArrayDeque<>();
        dq.addLast(new Pair(begin,0));
        
        while(!dq.isEmpty()){
            Pair cur = dq.removeFirst();
            if(cur.s.equals(target)) return cur.cnt;
            for(int i = 0; i < n; i++){
                if(isUsed[i]) continue;
                if(checkOne(cur.s,words[i])){
                    isUsed[i] = true;
                    dq.addLast(new Pair(words[i], cur.cnt + 1));
                }
            }
        }
        
        return 0;
    }
}