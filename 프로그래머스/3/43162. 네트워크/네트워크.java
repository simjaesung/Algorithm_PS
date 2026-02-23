import java.util.*;

class Solution {
    public int solution(int n, int[][] computers) {
        ArrayList<Integer>[] adj = new ArrayList[n+1];
        for(int i = 0; i <= n; i++) adj[i] = new ArrayList<>();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i==j) continue;
                if(computers[i][j] == 1){
                    adj[i+1].add(j+1);
                }
            }
        }
        
        int ans = 0;
        boolean[] visited = new boolean[n+1];
        for(int i = 1; i <= n; i++){
            if(visited[i]) continue;
            
            ans++;
            visited[i] = true;
            
            Deque<Integer> dq = new ArrayDeque<>();
            dq.addLast(i);
            
            while(!dq.isEmpty()){
                int cur = dq.removeFirst();
                for(int nxt : adj[cur]){
                    if(visited[nxt]) continue;
                    visited[nxt] = true;
                    dq.addLast(nxt);
                }
            }
        }
        
        return ans;
        
    }
    
}