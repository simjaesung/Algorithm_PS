//BFS로도 풀어보기
import java.util.*;

class Solution {
    // static class Pair{
    //     int x; int y;
    //     public Pair(int x, int y){
    //         this.x = x; this.y = y;
    //     }
    // }
    static int INF = Integer.MAX_VALUE;
    
    public int solution(int n, int[][] edge) {
        ArrayList<Integer>[] adj = new ArrayList[n+1];
        for(int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
        for(int[] ed : edge){
            adj[ed[0]].add(ed[1]);
            adj[ed[1]].add(ed[0]);
        }
        
        int[] dist = new int[n+1];
        boolean[] visited = new boolean[n+1];
        
        Deque<Integer> dq = new ArrayDeque<>();
        dq.addLast(1);
        visited[1] = true;
        
        while(!dq.isEmpty()){
            int cur = dq.removeFirst();
            for(int nxt : adj[cur]){
                if(visited[nxt]) continue;
                visited[nxt] = true;
                dist[nxt] = dist[cur] + 1;
                dq.addLast(nxt);
            }
        }
        
        int answer = 1;
        int maxVal = dist[1];
        for(int i = 2; i<=n; i++){
            if(dist[i] > maxVal){
                answer = 0;
                maxVal = dist[i];
            }
            if(dist[i] == maxVal) answer++;
        }
       return answer;
    }
}