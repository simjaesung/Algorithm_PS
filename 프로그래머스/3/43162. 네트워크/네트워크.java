import java.util.*;

class Solution {
    public int solution(int n, int[][] computers) {
        int ans = 0;
        boolean[] visited = new boolean[n];
        
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            
            ans++;
            visited[i] = true;
            
            Deque<Integer> dq = new ArrayDeque<>();
            dq.addLast(i);
            
            while(!dq.isEmpty()){
                int cur = dq.removeFirst();
                for(int nxt = 0; nxt < n; nxt++){
                    if(nxt == cur || computers[cur][nxt] == 0) continue;
                    if(visited[nxt]) continue;
                    visited[nxt] = true;
                    dq.addLast(nxt);
                }
            }
        }
        
        return ans;
        
    }
    
}