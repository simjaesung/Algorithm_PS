import java.util.*;

class Solution {
    static int ans = Integer.MAX_VALUE;
    static int n;
    static String gTarget;
    static String[] gWords;
    static boolean[] gUsed;
    public int solution(String begin, String target, String[] words) {
        n = words.length;
        gUsed = new boolean[n];
        gTarget = target;
        gWords = words;
        go(begin, 0);
        if(ans == Integer.MAX_VALUE) return 0;
        return ans;
    }
    
    public boolean isOne(String a, String b){
        int len = a.length();
        
        int cnt = 0;
        for(int i = 0; i < len; i++){
            if(a.charAt(i) != b.charAt(i)) cnt++;   
        }
        return cnt == 1;
    }
    
    public void go(String cur, int depth){
        if(cur.equals(gTarget)){
            ans = Math.min(ans, depth);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(gUsed[i]) continue;
            if(!isOne(cur, gWords[i])) continue;
            gUsed[i] = true;
            go(gWords[i], depth + 1);
            gUsed[i] = false;
        }
    }
}